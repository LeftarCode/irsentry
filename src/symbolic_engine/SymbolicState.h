#pragma once
#include "types/SIRType.h"
#include "variables/Value.h"
#include <iomanip>
#include <iostream>
#include <map>
#include <unordered_map>
#include <z3++.h>

namespace irsentry {
struct Allocation {
  z3::expr base;
  z3::expr size;
};

class SymbolicStore {
public:
  static constexpr unsigned PTR_BITS = 64;
  static constexpr unsigned PTR_BYTES = PTR_BITS / 8;
  z3::context ctx;
  z3::solver solver;

  explicit SymbolicStore();

  void bind(const Value &v, const z3::expr &e);
  void bind(const std::string n, const z3::expr &e);

  z3::expr lookup(const Value &v) const;
  z3::expr lookup(const std::string &n) const;

  z3::expr createPtr(uint64_t value);
  z3::expr createConstByte(const std::string &name);
  z3::expr createBV(const uint64_t &value, const z3::expr &ref);
  z3::expr createBool(const bool &value);
  z3::expr createConst(const std::string &name, const z3::sort &sort);
  z3::expr createConst(const std::string &name, const SIRTypePtr &type);

  Allocation &allocate(const std::string &name, const z3::expr &sizeBV);

  z3::expr load(const Allocation &A, const z3::expr &offset, unsigned bytes);
  z3::expr loadByte(const z3::expr &base);

  void store(const z3::expr &addr, const z3::expr &value);
  void storeBytes(const z3::expr &base, const std::string &bytes);

  void debugDumpModel(const z3::model &m) const;

private:
  uint64_t m_nextConcreteAddr = 0x100000;
  std::vector<Allocation> m_allocations;
  std::unordered_map<std::string, z3::expr> m_ssa;
  z3::expr m_memory;
};
} // namespace irsentry
