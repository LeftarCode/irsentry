#!/usr/bin/env python3
import re
import sys
import json

def to_pascal_case(s: str) -> str:
    return s[0].upper() + s[1:] if s else s

def rule_name_to_struct_name(rule_name: str) -> str:
    if rule_name.endswith("Inst"):
        base = rule_name[:-4]  # usuwa 'Inst'
        return to_pascal_case(base) + "Instruction"
    else:
        return to_pascal_case(rule_name) + "Instruction"

def parse_grammar(grammar_text: str):
    productions = []
    
    for production in grammar_text.split(';'):
        production = production.strip()
        if not production:
            continue
        m = re.match(r'(\w+)\s*:\s*(.*)', production, re.DOTALL)
        if not m:
            continue
        rule_name = m.group(1)
        body = m.group(2).strip()
        alternatives_raw = body.split('|')
        alternatives = []
        for alt in alternatives_raw:
            alt = alt.strip().replace('\n', ' ')
            raw_tokens = alt.split()
            tokens = []
            i = 0
            while i < len(raw_tokens):
                token = raw_tokens[i]
                if (token.startswith("'") and token.endswith("'")) or (token.startswith('"') and token.endswith('"')):
                    i += 1
                    continue
                if re.match(r'^[,]$', token):
                    i += 1
                    continue
                if token == '?':
                    if tokens:
                        prev_token, _ = tokens[-1]
                        tokens[-1] = (prev_token, True)
                    i += 1
                    continue
                tokens.append((token, False))
                i += 1
            alternatives.append(tokens)
        productions.append((rule_name, alternatives))
    return productions

def generate_structs(productions, settings):
    structs = []
    for rule_name, alternatives in productions:
        total_alts = len(alternatives)
        field_data = {}
        ordering = []
        for alt in alternatives:
            local_counts = {}
            for token, is_opt in alt:
                if token not in ordering:
                    ordering.append(token)
                if token not in local_counts:
                    local_counts[token] = {"count": 0, "required": False, "is_boolean": False}
                local_counts[token]["count"] += 1
                if not is_opt:
                    local_counts[token]["required"] = True
            for token, data in local_counts.items():
                if token not in field_data:
                    field_data[token] = {
                        "max_count": data["count"],
                        "appears_in": 1,
                        "required_in": 1 if data["required"] else 0
                    }
                else:
                    field_data[token]["max_count"] = max(field_data[token]["max_count"], data["count"])
                    field_data[token]["appears_in"] += 1
                    if data["required"]:
                        field_data[token]["required_in"] += 1
        fields = []
        for token in ordering:
            if token in field_data:
                count = field_data[token]["max_count"]
                appears_in = field_data[token]["appears_in"]
                required_in = field_data[token]["required_in"]
                is_required = (appears_in == total_alts and required_in == total_alts)
                is_boolean = False
                if token in settings["optional_fields_order"]:
                    is_required = False
                if token in settings["boolean_fields"]:
                    is_boolean = True
                fields.append((token, count, is_required, is_boolean))
        struct_name = rule_name_to_struct_name(rule_name)
        structs.append({
            "rule_name": rule_name,
            "struct_name": struct_name,
            "fields": fields
        })
    return structs

def generate_cpp_code(structs):
    lines = []
    lines.append("enum InstructionType {")
    enum_names = [s["struct_name"] for s in structs]
    lines.append("    " + ", ".join(enum_names))
    lines.append("};\n")
    
    for s in structs:
        lines.append("class {} : public Instruction {{\npublic:".format(s["struct_name"]))
        for token, count, is_required, is_boolean in s["fields"]:
            if is_required:
                type_name = "bool" if is_boolean else to_pascal_case(token)
                field_name = token
                decl = "{} {}".format(type_name, field_name)
            else:
                if token.startswith("opt"):
                    type_name = "bool" if is_boolean else to_pascal_case(token[3:])
                    field_name = token
                    decl = "{} {}".format(type_name, field_name)
                else:
                    type_name = "bool" if is_boolean else to_pascal_case(token)
                    field_name = "opt" + to_pascal_case(token)
                    decl = "std::optional<{}> {}".format(type_name, field_name)
            if count > 1:
                if is_required:
                    decl = "std::array<{}, {}> {}".format(type_name, count, token)
                else:
                    decl = "std::array<std::optional<{}>, {}> opt{}".format(type_name, count, to_pascal_case(token))
            lines.append("    " + decl + ";")
        lines.append("};\n")
    return "\n".join(lines)

def main():
    if len(sys.argv) < 2:
        print("Usage: python generate_structs.py <plik.g4>")
        sys.exit(1)
    filename = sys.argv[1]
    with open(filename, "r") as f:
        grammar_text = f.read()
    
    settings = {}
    with open("./settings.json", "r") as f:
        settings = json.loads(f.read())
    
    productions = parse_grammar(grammar_text)
    structs = generate_structs(productions, settings)
    cpp_code = generate_cpp_code(structs)
    print(cpp_code)

if __name__ == "__main__":
    main()
