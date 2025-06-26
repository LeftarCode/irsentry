#pragma once
#include <cstdint>
#include <memory>
#include <string>
#include <unordered_map>
#include <variant>
#include <vector>

namespace irsentry {

using SIRTypePtr = std::shared_ptr<class SIRType>;

enum class BaseScalar {
  Void,
  Bool,
  Int8,
  Int16,
  Int32,
  Int64,
  Uint8,
  Uint16,
  Uint32,
  Uint64,
  Float16,
  Float32,
  Float64,
  Float80,
  Float128
};

enum class Signedness { Signless, Signed, Unsigned };
struct IntCustom {
  uint32_t bits;
  Signedness sign;
};

struct Ptr {
  std::shared_ptr<class SIRType> pointee;
};
struct Array {
  uint64_t num;
  std::shared_ptr<class SIRType> elem;
};
struct Vec {
  uint64_t num;
  std::shared_ptr<class SIRType> elem;
};
struct Struct {
  std::vector<std::shared_ptr<class SIRType>> fields;
};
struct Func {
  std::shared_ptr<class SIRType> ret;
  std::vector<std::shared_ptr<class SIRType>> params;
  bool varArg = false;
};
struct Named {
  std::string name;
};

using TypeRepr =
    std::variant<BaseScalar, IntCustom, Ptr, Array, Vec, Struct, Func, Named>;

class SIRType : public std::enable_shared_from_this<SIRType> {
public:
  template <typename T, typename... Args>
  static std::shared_ptr<SIRType> make(Args &&...args);

  template <typename T> bool is() const {
    return std::holds_alternative<T>(repr);
  }
  template <typename T> const T &as() const { return std::get<T>(repr); }

  template <typename... Fns> decltype(auto) match(Fns &&...f) const {
    struct Over : Fns... {
      using Fns::operator()...;
    };
    return std::visit(Over{std::forward<Fns>(f)...}, repr);
  }

private:
  explicit SIRType(TypeRepr r) : repr(std::move(r)) {}
  TypeRepr repr;

  struct Pool {
    static Pool &get();
    std::shared_ptr<SIRType> intern(TypeRepr r);

  private:
    std::unordered_map<std::size_t, std::weak_ptr<SIRType>> cache;
  };
};

template <typename T, typename... Args>
std::shared_ptr<SIRType> SIRType::make(Args &&...args) {
  return Pool::get().intern(TypeRepr{T{std::forward<Args>(args)...}});
}

} // namespace irsentry
