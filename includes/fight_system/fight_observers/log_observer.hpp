#include <fstream>

#include <fight_system/fight_observers/fight_observer.hpp>

namespace fight_system::fight_observers {
class LogObserver : public FightObserver {
public:
  LogObserver(const std::string &filename);
  void OnDefeat(const npcs::NPC &winner, const npcs::NPC &loser) override;

private:
  std::ofstream filestream_;
};
} // namespace fight_system::fight_observers
