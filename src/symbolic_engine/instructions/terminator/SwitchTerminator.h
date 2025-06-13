#pragma once
#include "../../variables/Value.h"
#include <string>
#include <utility>
#include <vector>

namespace irsentry {

/// Pojedynczy <wartoœæ-case, etykieta-bloku>
struct SwitchCase {
  Value value;           // sta³a porównywana z condition
  std::string successor; // dok¹d prowadzi ta ga³¹Ÿ
};

class SwitchTerminator {
public:
  Value condition;               // %x z instrukcji switch
  std::vector<SwitchCase> cases; // wszystkie pary (C, BB)
  std::string defaultSuccessor;  // blok domyœlny
};

} // namespace irsentry
