#pragma once

#include <memory>
#include <vector>

#include <fight_system/fight_observers/fight_observer.hpp>
#include <npc_factory/npc_factory.hpp>

namespace fight_system {
//NPC with lexicographically smallest names will fight first
class FightManager {
public:
  FightManager(const npc_factory::NPCFactory &factory);
  FightManager(
      const npc_factory::NPCFactory &factory,
      std::initializer_list<std::shared_ptr<fight_observers::FightObserver>>
          observers);
  void StartFighting(float attack_range);
  void AddObserver(std::shared_ptr<fight_observers::FightObserver> observer);
  void
  RemoveObserver(std::shared_ptr<fight_observers::FightObserver> observer);
private:
  void Notify(const npcs::NPC& winner, const npcs::NPC& loser_name);

private:
  std::vector<std::shared_ptr<fight_observers::FightObserver>> observers_;
  const npc_factory::NPCFactory &factory_;
};
}; // namespace fight_system
