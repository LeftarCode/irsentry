#include "SEETypeDef.h"

namespace irsentry {
std::shared_ptr<SEETypeDef> SEETypeDef::makeVoid() {
  auto p = std::make_shared<SEETypeDef>();
  p->info = ScalarInfo{ScalarKind::Void};
  return p;
}

std::shared_ptr<SEETypeDef> SEETypeDef::makeBoolean() {
  auto p = std::make_shared<SEETypeDef>();
  p->info = ScalarInfo{ScalarKind::Boolean};
  return p;
}

std::shared_ptr<SEETypeDef> SEETypeDef::makeInteger(uint32_t bits,
                                                    Signedness s) {
  auto p = std::make_shared<SEETypeDef>();
  p->info = ScalarInfo{ScalarKind::Integer, bits, s};
  return p;
}

std::shared_ptr<SEETypeDef> SEETypeDef::makeFloat(ScalarKind fpKind) {
  auto p = std::make_shared<SEETypeDef>();
  p->info = ScalarInfo{fpKind};
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

bool SEETypeDef::isInteger() const {
  if (!std::holds_alternative<ScalarInfo>(info))
    return false;

  const auto &S = std::get<ScalarInfo>(info);
  return S.kind == ScalarKind::Integer;
}

bool SEETypeDef::isFloat() const {
  if (!std::holds_alternative<ScalarInfo>(info)) {
    return false;
  }

  switch (std::get<ScalarInfo>(info).kind) {
  case ScalarKind::Float16:
  case ScalarKind::Float32:
  case ScalarKind::Float64:
  case ScalarKind::Float128:
    return true;
  default:
    return false;
  }
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
