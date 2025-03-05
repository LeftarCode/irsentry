import re
import sys

def generate_cpp_for_rule(rule_name, production):
    tokens = re.findall(r"'[^']*'|\w+", production)
    child_tokens = [token for token in tokens if not (token.startswith("'") and token.endswith("'"))]
    
    seen = set()
    unique_child_tokens = []
    for token in child_tokens:
        if token not in seen:
            seen.add(token)
            unique_child_tokens.append(token)
    
    lines = []
    lines.append(f"else if (auto *{rule_name} = ctx->{rule_name}()) {{")
    for token in unique_child_tokens:
        lines.append(f"    auto {token} = {rule_name}->{token}();")
    
    lines.append(f"    throw std::runtime_error(\"Unimplemented instruction {rule_name}!\");")
    lines.append("}")
    
    return "\n".join(lines)

def generate_cpp_code(grammar_text):
    pattern = r"(\w+)\s*:\s*(.*?)\s*;"
    matches = re.findall(pattern, grammar_text, re.DOTALL)
    
    cpp_snippets = []
    for rule_name, production in matches:
        production_clean = " ".join(production.split())
        snippet = generate_cpp_for_rule(rule_name, production_clean)
        cpp_snippets.append(snippet)
    
    return "\n\n".join(cpp_snippets)

def main(grammar_file_path):
    with open(grammar_file_path, "r", encoding="utf-8") as file:
        grammar_text = file.read()
    
    cpp_code = generate_cpp_code(grammar_text)
    print(cpp_code)

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python generate_cpp.py <grammar_file.g4>")
        sys.exit(1)
    
    main(sys.argv[1])
