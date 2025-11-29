#include <fight_system/fight_observers/in_memory_observer.hpp>

namespace fight_system::fight_observers {
void InMemoryObserver::OnDefeat(const npcs::NPC &winner,
                                const npcs::NPC &loser) {
  results_.push_back(
      FightResult{std::string{winner.GetName()}, std::string{loser.GetName()}});
}
std::string_view InMemoryObserver::GetWinner(std::size_t idx) const {
  return results_[idx].winner_name;
}
std::string_view InMemoryObserver::GetLoser(std::size_t idx) const {
  return results_[idx].loser_name;
}
std::size_t InMemoryObserver::GetLength() const { return results_.size(); }
} // namespace fight_system::fight_observers
