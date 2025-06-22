#pragma once
#include "../types/IntX.h"
#include "../types/SIRType.h"
#include <array>
#include <optional>
#include <string>
#include <variant>
#include <vector>

namespace irsentry {

struct Float80Bits {
  std::array<std::uint8_t, 10> bytes{};
};

struct ArrayConstant {
  std::vector<struct Constant> elements;
};

using ScalarConstant = std::variant<std::monostate, bool, float, double,
                                    long double, Float80Bits, IntX>;
using ConstantPayload = std::variant<ScalarConstant, ArrayConstant>;

struct Constant {
  ConstantPayload value;

  Constant() = default;
  Constant(ScalarConstant sc) : value(std::move(sc)) {}
  Constant(ArrayConstant ac) : value(std::move(ac)) {}

  bool isScalar() const {
    return std::holds_alternative<ScalarConstant>(value);
  }
  bool isArray() const { return std::holds_alternative<ArrayConstant>(value); }

  const ScalarConstant &asScalar() const {
    return std::get<ScalarConstant>(value);
  }
  const ArrayConstant &asArray() const {
    return std::get<ArrayConstant>(value);
  }
};

struct Variable {
  std::string name;
};
struct Undef {};
struct Poison {};

using ValuePayload = std::variant<Undef, Poison, Constant, Variable>;

using SIRTypePtr = std::shared_ptr<SIRType>;

class Value {
public:
  explicit Value() = default;
  explicit Value(SIRTypePtr ty) : type(std::move(ty)) {}
  Value(SIRTypePtr ty, Constant c)
      : type(std::move(ty)), payload(std::move(c)) {}
  Value(SIRTypePtr ty, Variable v)
      : type(std::move(ty)), payload(std::move(v)) {}
  Value(SIRTypePtr ty, Undef u) : type(std::move(ty)), payload(u) {}
  Value(SIRTypePtr ty, Poison p) : type(std::move(ty)), payload(p) {}

  bool isConstant() const { return std::holds_alternative<Constant>(payload); }
  bool isVariable() const { return std::holds_alternative<Variable>(payload); }
  bool isUndef() const { return std::holds_alternative<Undef>(payload); }
  bool isPoison() const { return std::holds_alternative<Poison>(payload); }

  const Constant &asConst() const { return std::get<Constant>(payload); }
  const Variable &asVar() const { return std::get<Variable>(payload); }

  SIRTypePtr type;
  ValuePayload payload;
};
} // namespace irsentry
