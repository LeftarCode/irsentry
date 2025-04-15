#pragma once

namespace irsentry {
enum class ICmpPred { Eq, Ne, Sge, Sgt, Sle, Slt, Uge, Ugt, Ule, Ult };
enum class FCmpPred {
  False,
  Oeq,
  Oge,
  Ogt,
  Ole,
  Olt,
  One,
  Ord,
  True,
  Ueq,
  Uge,
  Ugt,
  Ule,
  Ult,
  Une,
  Uno
};
} // namespace irsentry
