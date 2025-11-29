#include <fight_system/fight_observers/cout_observer.hpp>

#include <iostream>

namespace fight_system::fight_observers {

void CoutObserver::OnDefeat(const npcs::NPC &winner, const npcs::NPC &loser) {
  std::cout << winner.GetName() << " has killed " << loser.GetName() << '\n';
}
} // namespace fight_system::fight_observers
