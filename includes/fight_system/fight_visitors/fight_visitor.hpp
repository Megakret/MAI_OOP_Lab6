#pragma once

#include <NPCs/AllNPC.hpp>

namespace fight_system::fight_visitors {
class FightVisitor {
  virtual bool Fight(const npcs::Orc &orc) = 0;
  virtual bool Fight(const npcs::Brigand &brigand) = 0;
  virtual bool Fight(const npcs::Werewolf &werewolf) = 0;
};
}; // namespace fight_manager::fight_visitors
