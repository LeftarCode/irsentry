#pragma once
#include <variant>

#include "BaseInstruction.h"

#include "bit/AShrInstruction.h"
#include "bit/AndInstruction.h"
#include "bit/LShrInstruction.h"
#include "bit/OrInstruction.h"
#include "bit/ShlInstruction.h"
#include "bit/XorInstruction.h"

#include "cast/CastInstruction.h"
#include "cmp/FCmpInstruction.h"
#include "cmp/ICmpInstruction.h"

#include "memory/ExtractElementInstruction.h"

#include "value/AddInstruction.h"
#include "value/FAddInstruction.h"
#include "value/FDivInstruction.h"
#include "value/FMulInstruction.h"
#include "value/FRemInstruction.h"
#include "value/FSubInstruction.h"
#include "value/MulInstruction.h"
#include "value/SDivInstruction.h"
#include "value/SRemInstruction.h"
#include "value/SubInstruction.h"
#include "value/UDivInstruction.h"
#include "value/URemInstruction.h"

namespace irsentry {}
