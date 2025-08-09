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
  CastInstruction(SIRTypePtr dataTypeFrom, SIRTypePtr dataTypeTo,
                  CastInstrType type) {
    result = Value(dataTypeTo);
    from = Value(dataTypeFrom);
    this->type = type;
  }

  Value result;
  Value from;
  CastInstrType type;
};
} // namespace irsentry
