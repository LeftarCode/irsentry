#include "SymbolicState.h"
#include "../utilities/helpers/Z3Helper.h"
#include <z3++.h>

inline uint64_t align16(uint64_t x) { return (x + 15) & ~uint64_t(15); }

namespace irsentry {

SymbolicStore::SymbolicStore()
    : solver(ctx),
      m_memory(ctx.constant(
          "mem0", ctx.array_sort(ctx.bv_sort(PTR_BITS), ctx.bv_sort(8)))) {}

void SymbolicStore::bind(const Value &v, const z3::expr &e) {
  if (!v.isVariable()) {
    throw std::logic_error("bind(): Value has no Variable payload");
  }
  m_ssa.insert_or_assign(v.asVar().name, e);
}

void SymbolicStore::bind(const std::string n, const z3::expr &e) {
  m_ssa.insert_or_assign(n, e);
}

z3::expr SymbolicStore::lookup(const Value &v) const {
  return m_ssa.at(v.asVar().name);
}

z3::expr SymbolicStore::lookup(const std::string &n) const {
  return m_ssa.at(n);
}

Allocation &SymbolicStore::allocate(const std::string &name,
                                    const z3::expr &sizeBV, SIRTypePtr elemTy) {
  constexpr uint64_t DEFAULT_BYTES = 4096;

  uint64_t sizeConst = 0;
  bool isConst = Z3_is_numeral_ast(ctx, sizeBV);

  if (isConst) {
    sizeConst = sizeBV.get_numeral_uint64();
  } else {
    sizeConst = DEFAULT_BYTES;
    z3::expr realSz = sizeBV;
    z3::expr limit = ctx.bv_val(DEFAULT_BYTES, PTR_BITS);
    solver.add(realSz <= limit);
  }

  m_nextConcreteAddr = align16(m_nextConcreteAddr);
  uint64_t baseConst = m_nextConcreteAddr;
  m_nextConcreteAddr = align16(m_nextConcreteAddr + sizeConst);

  z3::expr base = ctx.bv_val(baseConst, PTR_BITS);

  z3::expr arr =
      ctx.constant((name + "_arr").c_str(),
                   ctx.array_sort(ctx.bv_sort(PTR_BITS), ctx.bv_sort(8)));

  m_allocations.emplace_back(Allocation{base, sizeBV, elemTy, arr});
  return m_allocations.back();
}

z3::expr SymbolicStore::load(const Allocation &A, const z3::expr &offset,
                             unsigned bytes) {
  z3::expr val = ctx.bv_val(0, bytes * 8);
  for (unsigned i = 0; i < bytes; ++i) {
    z3::expr addr = A.base + offset + ctx.bv_val(i, PTR_BITS);
    z3::expr byte = z3::select(A.data, addr);
    val = z3::concat(byte, val);
  }
  return val.extract(bytes * 8 - 1, 0);
}

z3::expr SymbolicStore::loadByte(const z3::expr &base) {
  return z3::select(m_memory, base);
}

void SymbolicStore::store(const z3::expr &addr, const z3::expr &value) {
  unsigned bytes = value.get_sort().bv_size() / 8;
  for (unsigned i = 0; i < bytes; ++i) {
    z3::expr byte = value.extract(i * 8 + 7, i * 8);
    z3::expr a = addr + ctx.bv_val(i, PTR_BITS);
    m_memory = z3::store(m_memory, a, byte);
  }
}

void SymbolicStore::writeBytes(const z3::expr &base, const std::string &bytes) {
  for (unsigned i = 0; i < bytes.size(); ++i) {
    m_memory = z3::store(m_memory, base + ctx.bv_val(i, PTR_BITS),
                         ctx.bv_val(static_cast<uint8_t>(bytes[i]), 8));
  }
}

void SymbolicStore::debugDumpModel(const z3::model &m) const {

  auto show = [&](const std::string &name, const z3::expr &e) {
    std::cout << name << " = " << m.eval(e, true) << '\n';
  };

  std::cout << "=== SSA variables ===\n";
  for (const auto &[n, e] : m_ssa) {
    show(n, e);
  }
  std::cout << '\n';

  Z3Helper::dumpMemory(m, m_memory, 1024);
}

}; // namespace irsentry
