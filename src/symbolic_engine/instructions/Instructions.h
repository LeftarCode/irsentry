#pragma once
#include "bit/BitwiseInstruction.h"
#include "branch/CallInstruction.h"
#include "cast/CastInstruction.h"
#include "cmp/FCmpInstruction.h"
#include "cmp/ICmpInstruction.h"
#include "memory/AddrSpaceCastInteruction.h"
#include "memory/AllocaInstruction.h"
#include "memory/ExtractElementInstruction.h"
#include "memory/ExtractValueInstruction.h"
#include "memory/GetElementPtrInstruction.h"
#include "memory/InsertElementInstruction.h"
#include "memory/InsertValueInstruction.h"
#include "memory/LoadInstruction.h"
#include "memory/PhiInstruction.h"
#include "memory/SelectInstruction.h"
#include "memory/ShuffleVectorInstruction.h"
#include "memory/StoreInstruction.h"
#include "terminator/BrTerminator.h"
#include "terminator/RetTerminator.h"
#include "terminator/SwitchTerminator.h"
#include "terminator/UnreachableTerminator.h"
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
                 BrTerminator, RetTerminator, ExtractElementInstruction,
                 InsertElementInstruction, ShuffleVectorInstruction,
                 InsertValueInstruction, PhiInstruction,
                 AddrSpaceCastInstruction, UnreachableTerminator,
                 SwitchTerminator, SelectInstruction>;
} // namespace irsentry

namespace irsentry {}
