#pragma once
#include <memory>
#include <string>
#include <variant>
#include <vector>

namespace irsentry {
enum ScalarKind {
  Void,
  Boolean,
  Named,
  Integer,
  Float16,
  Float32,
  Float64,
  Float80,
  Float128,
  Ptr
};

enum class Signedness { Signless, Signed, Unsigned };

struct SEETypeDef;
using SEETypeDefPtr = std::shared_ptr<SEETypeDef>;

struct ScalarInfo {
  ScalarKind kind;
  uint32_t bitWidth = 0;
  Signedness signedness = Signedness::Signless;
};

struct ArrayInfo {
  uint64_t numElements;
  SEETypeDefPtr elementType;
};

struct VectorInfo {
  uint64_t numElements;
  SEETypeDefPtr elementType;
};

struct StructField {
  SEETypeDefPtr type;
};

struct PointerInfo {
  SEETypeDefPtr type;
};

struct FuncInfo {
  SEETypeDefPtr returnType;
  std::vector<SEETypeDefPtr> paramTypes;
  bool isVarArg = false;
};

struct NamedInfo {
  std::string name;
};

using StructInfo = std::vector<StructField>;
using TypeInfo = std::variant<ScalarInfo, ArrayInfo, PointerInfo, VectorInfo,
                              StructInfo, FuncInfo, NamedInfo>;

class SEETypeDef {
public:
  SEETypeDef() {};
  TypeInfo info;

  static SEETypeDefPtr makeVoid();
  static SEETypeDefPtr makeBoolean();
  static SEETypeDefPtr makeInteger(uint32_t bits,
                                   Signedness s = Signedness::Signless);
  static SEETypeDefPtr makeFloat(ScalarKind fpKind);

  static SEETypeDefPtr makeArray(uint64_t n, SEETypeDefPtr elem);
  static SEETypeDefPtr makeVector(uint64_t n, SEETypeDefPtr elem);
  static SEETypeDefPtr makeStruct(StructInfo fields);
  static SEETypeDefPtr makePointer(SEETypeDefPtr type);
  static SEETypeDefPtr makeFunction(SEETypeDefPtr ret,
                                    std::vector<SEETypeDefPtr> params,
                                    bool isVarArg = false);
  static SEETypeDefPtr makeNamed(std::string name);

  bool isScalar() const;
  bool isInteger() const;
  bool isFloat() const;
  bool isArray() const;
  bool isVector() const;
  bool isStruct() const;
  bool isPointer() const;
  bool isFunction() const;
  bool isNamed() const;
};
} // namespace irsentry
