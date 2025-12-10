#pragma once

#include<fight_system/fight_observers/fight_observer.hpp>

namespace fight_system::fight_observers {
class CoutObserver: public FightObserver {
public:
  void OnDefeat(const npcs::NPC &winner, const npcs::NPC &loser) override;
};
}; // namespace fight_system::fight_observers

