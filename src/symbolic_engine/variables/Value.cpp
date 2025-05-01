#include "Value.h"

irsentry::Value::Value(SEETypeDefPtr dataType)
    : dataType(std::move(dataType)), isVariable(false) {}
