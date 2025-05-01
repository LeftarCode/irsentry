#include "SEETypeDef.h"

namespace irsentry {
SEETypeDefPtr SEETypeDef::makeScalar(ScalarType t) {
  auto p = std::make_shared<SEETypeDef>();
  p->info = ScalarInfo{t};
  return p;
}
SEETypeDefPtr SEETypeDef::makeArray(uint64_t n, SEETypeDefPtr elem) {
  auto p = std::make_shared<SEETypeDef>();
  p->info = ArrayInfo{n, std::move(elem)};
  return p;
}
SEETypeDefPtr SEETypeDef::makeVector(uint64_t n, SEETypeDefPtr elem) {
  auto p = std::make_shared<SEETypeDef>();
  p->info = VectorInfo{n, std::move(elem)};
  return p;
}
SEETypeDefPtr SEETypeDef::makeStruct(StructInfo fields) {
  auto p = std::make_shared<SEETypeDef>();
  p->info = std::move(fields);
  return p;
}

SEETypeDefPtr SEETypeDef::makePointer(SEETypeDefPtr type) {
  auto p = std::make_shared<SEETypeDef>();
  p->info = PointerInfo{type};
  return p;
}

SEETypeDefPtr SEETypeDef::makeFunction(SEETypeDefPtr ret,
                                       std::vector<SEETypeDefPtr> params,
                                       bool isVarArg) {
  auto p = std::make_shared<SEETypeDef>();
  p->info = FuncInfo{std::move(ret), std::move(params), isVarArg};
  return p;
}

SEETypeDefPtr SEETypeDef::makeNamed(std::string name) {
  auto p = std::make_shared<SEETypeDef>();
  p->info = NamedInfo{name};
  return p;
}

bool SEETypeDef::isScalar() const {
  return std::holds_alternative<ScalarInfo>(info);
}
bool SEETypeDef::isArray() const {
  return std::holds_alternative<ArrayInfo>(info);
}
bool SEETypeDef::isVector() const {
  return std::holds_alternative<VectorInfo>(info);
}
bool SEETypeDef::isStruct() const {
  return std::holds_alternative<StructInfo>(info);
}
bool SEETypeDef::isPointer() const {
  return std::holds_alternative<PointerInfo>(info);
}

bool SEETypeDef::isFunction() const {
  return std::holds_alternative<FuncInfo>(info);
}

bool SEETypeDef::isNamed() const {
  return std::holds_alternative<NamedInfo>(info);
}

} // namespace irsentry
