#include <fight_system/fight_manager.hpp>

#include <algorithm>
#include <set>

#include <fight_system/fight_observers/fight_observer.hpp>

namespace fight_system {

FightManager::FightManager(const npc_factory::NPCFactory &factory)
    : factory_(factory) {}
FightManager::FightManager(
    const npc_factory::NPCFactory &factory,
    std::initializer_list<std::shared_ptr<fight_observers::FightObserver>>
        observers)
    : observers_(observers), factory_(factory) {}
void FightManager::AddObserver(
    std::shared_ptr<fight_observers::FightObserver> observer) {
  observers_.push_back(observer);
}
void FightManager::RemoveObserver(
    std::shared_ptr<fight_observers::FightObserver> observer) {
  auto it = std::find(observers_.begin(), observers_.end(), observer);
  observers_.erase(it);
}
void FightManager::Notify(const npcs::NPC &winner, const npcs::NPC &loser) {
  for (auto obs : observers_) {
    obs->OnDefeat(winner, loser);
  }
}
void FightManager::StartFighting(float attack_range) {
  std::set<std::shared_ptr<npcs::NPC>> dead_npcs;
  std::vector<std::shared_ptr<npcs::NPC>> npcs;
  npcs.reserve(factory_.GetNPCs().size());
  for (auto &[name, npc] : factory_.GetNPCs()) {
    npcs.push_back(npc);
  }
  for (std::size_t i = 0; i < npcs.size(); ++i) {
    auto opponent1 = npcs[i];
    if (dead_npcs.contains(opponent1)) {
      continue;
    }
    for (std::size_t j = i + 1; j < npcs.size(); ++j) {
      auto opponent2 = npcs[j];
      if (dead_npcs.contains(opponent2)) {
        continue;
      }
      if (npcs::Distance(opponent1->GetCoords(), opponent2->GetCoords()) >
          attack_range) {
        continue;
      }
      bool has_opponent1_killed = opponent1->Fight(*opponent2);
      bool has_opponent2_killed = opponent2->Fight(*opponent1);
      if (has_opponent1_killed) {
        Notify(*opponent1, *opponent2);
      }
      if (has_opponent2_killed) {
        Notify(*opponent2, *opponent1);
      }
      if (has_opponent1_killed) {
        dead_npcs.insert(opponent2);
      }
      if (has_opponent2_killed) {
        dead_npcs.insert(opponent1);
				break;
      }
    }
  }
}
} // namespace fight_system
