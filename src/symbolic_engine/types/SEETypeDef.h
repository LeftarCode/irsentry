#pragma once
#include <memory>
#include <string>
#include <variant>
#include <vector>

namespace irsentry {
enum ScalarType {
  Void,
  Boolean,
  Named,
  Int16,  /**< 16-bit signed integer */
  Int32,  /**< 32-bit signed integer */
  Int64,  /**< 64-bit signed integer */
  UInt16, /**< 16-bit unsigned integer */
  UInt32, /**< 32-bit unsigned integer */
  UInt64, /**< 64-bit unsigned integer */
  Float,  /**< Single-precision floating point */
  Double, /**< Double-precision floating point */
  Ptr     /**< Represents a pointer */
};

using TypeVariant = std::variant<bool, float, double, int16_t, int32_t, int64_t,
                                 uint16_t, uint32_t, uint64_t>;

struct SEETypeDef;
using SEETypeDefPtr = std::shared_ptr<SEETypeDef>;

struct ScalarInfo {
  ScalarType type;
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
  enum VariantIndex : size_t {
    Scalar = 0,
    Array = 1,
    Pointer = 2,
    Struct = 3,
    Vector = 4,
    Function = 5,
    Named = 6
  };

public:
  SEETypeDef() {};
  TypeInfo info;

  static SEETypeDefPtr makeScalar(ScalarType scalarType);
  static SEETypeDefPtr makeArray(uint64_t n, SEETypeDefPtr elem);
  static SEETypeDefPtr makeVector(uint64_t n, SEETypeDefPtr elem);
  static SEETypeDefPtr makeStruct(StructInfo fields);
  static SEETypeDefPtr makePointer(SEETypeDefPtr type);
  static SEETypeDefPtr makeFunction(SEETypeDefPtr ret,
                                    std::vector<SEETypeDefPtr> params,
                                    bool isVarArg = false);
  static SEETypeDefPtr makeNamed(std::string name);

  bool isScalar() const;
  bool isArray() const;
  bool isVector() const;
  bool isStruct() const;
  bool isPointer() const;
  bool isFunction() const;
  bool isNamed() const;
};
} // namespace irsentry
