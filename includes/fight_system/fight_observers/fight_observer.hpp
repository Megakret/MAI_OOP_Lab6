#pragma once

#include <NPCs/NPC.hpp>

namespace fight_system::fight_observers {
class FightObserver {
public:
  virtual void OnDefeat(const npcs::NPC &winner, const npcs::NPC &loser) = 0;
  virtual ~FightObserver() = default;
};
}; // namespace fight_system::fight_observers
