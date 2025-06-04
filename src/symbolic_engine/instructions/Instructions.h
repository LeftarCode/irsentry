#pragma once
#include "bit/BitwiseInstruction.h"
#include "branch/CallInstruction.h"
#include "cast/CastInstruction.h"
#include "cmp/FCmpInstruction.h"
#include "cmp/ICmpInstruction.h"
#include "memory/AllocaInstruction.h"
#include "memory/ExtractValueInstruction.h"
#include "memory/GetElementPtrInstruction.h"
#include "memory/LoadInstruction.h"
#include "memory/StoreInstruction.h"
#include "terminator/BrTerminator.h"
#include "terminator/RetTerminator.h"
#include "value/ValueInstruction.h"
#include <memory>
#include <new>
#include <utility>
#include <variant>

namespace irsentry {
// FIXME: Replace that nonelegant void*
using SEEInstruction =
    std::variant<void *, BitwiseInstruction, CastInstruction, FCmpInstruction,
                 ICmpInstruction, ValueInstruction, CallInstruction,
                 LoadInstruction, StoreInstruction, AllocaInstruction,
                 GetElementPtrInstruction, ExtractValueInstruction,
                 BrTerminator, RetTerminator>;
} // namespace irsentry

namespace irsentry {}
