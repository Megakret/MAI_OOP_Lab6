#pragma once

#include <vector>

#include <fight_system/fight_observers/fight_observer.hpp>

namespace fight_system::fight_observers {
class InMemoryObserver : public FightObserver {
public:
  struct FightResult {
    std::string winner_name;
    std::string loser_name;
  };
  void OnDefeat(const npcs::NPC &winner, const npcs::NPC &loser) override;
  std::string_view GetWinner(std::size_t idx) const;
  std::string_view GetLoser(std::size_t idx) const;
  std::size_t GetLength() const;

private:
  std::vector<FightResult> results_;
};
} // namespace fight_system::fight_observers
