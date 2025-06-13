#pragma once
#include "../../variables/Value.h"
#include <string>
#include <utility>
#include <vector>

namespace irsentry {

/// Pojedynczy <warto��-case, etykieta-bloku>
struct SwitchCase {
  Value value;           // sta�a por�wnywana z condition
  std::string successor; // dok�d prowadzi ta ga���
};

class SwitchTerminator {
public:
  Value condition;               // %x z instrukcji switch
  std::vector<SwitchCase> cases; // wszystkie pary (C, BB)
  std::string defaultSuccessor;  // blok domy�lny
};

} // namespace irsentry
