#pragma once
#include "../types/IntX.h"
#include "../types/SIRType.h"
#include <array>
#include <optional>
#include <string>
#include <variant>

namespace irsentry {

struct Float80Bits {
  std::array<std::uint8_t, 10> bytes{};
};

using ScalarConstant = std::variant<std::monostate, bool, float, double,
                                    long double, Float80Bits, IntX>;

struct Constant {
  ScalarConstant value;
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
