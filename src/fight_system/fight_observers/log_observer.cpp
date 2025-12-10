#include <fight_system/fight_observers/log_observer.hpp>

namespace fight_system::fight_observers {

LogObserver::LogObserver(const std::string &filename) : filestream_(filename) {}
void LogObserver::OnDefeat(const npcs::NPC &winner, const npcs::NPC &loser) {
  filestream_ << winner.GetName() << " has killed " << loser.GetName() << '\n';
}
} // namespace fight_system::fight_observers
