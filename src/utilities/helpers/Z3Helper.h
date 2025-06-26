#pragma once
#include "../../symbolic_engine/translators/ValueTranslator.h"
#include "../../symbolic_engine/variables/Value.h"
#include <z3++.h>

namespace irsentry {

class Z3Helper {
public:
  static uint64_t byteSizeOf(const SIRTypePtr &ty);

  static z3::expr translateValueAsBV(z3::context &ctx, SymbolicStore &env,
                                     const Value &v, unsigned width,
                                     const std::string_view hint = "");
  static uint8_t evalByte(const z3::model &mdl, const z3::expr &e);
  static void collectStores(const z3::expr &arr, const z3::model &mdl,
                            std::map<uint64_t, uint8_t> &out);
  static void dumpMemoryRange(const z3::model &m, const z3::expr &memory,
                              uint64_t from, unsigned n);
  static void dumpMemory(const z3::model &m, const z3::expr &memory,
                         unsigned maxBytes);
};

} // namespace irsentry
