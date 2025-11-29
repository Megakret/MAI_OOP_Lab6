#pragma once

#include <NPCs/AllNPC.hpp>

namespace fight_system {
namespace fight_visitors {
class FightVisitor {
public:
  virtual bool Fight(const npcs::Orc &orc) const = 0;
  virtual bool Fight(const npcs::Brigand &brigand) const = 0;
  virtual bool Fight(const npcs::Werewolf &werewolf) const = 0;
};
} // namespace fight_visitors
}; // namespace fight_system
