#pragma once
#include "../../variables/Value.h"
#include <array>

namespace irsentry {

enum class CastInstrType : std::uint8_t {
  Trunc,
  ZExt,
  SExt,
  FPTrunc,
  FPExt,
  FPToUI,
  FPToSI,
  UIToFP,
  SIToFP,
  PtrToInt,
  IntToPtr,
  BitCast,
  AddrSpaceCast
};

class CastInstruction {
public:
  CastInstruction() = default;
  CastInstruction(SEETypeDefPtr dataTypeFrom, SEETypeDefPtr dataTypeTo) {

    result = Value(dataTypeTo);
    from = Value(dataTypeFrom);
  }

  Value result;
  Value from;
};
} // namespace irsentry
