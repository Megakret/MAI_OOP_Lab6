#pragma once

#include <fight_system/fight_visitors/fight_visitor.hpp>

namespace fight_system {
namespace fight_visitors {
class OrcFightVisitor : public FightVisitor {
public:
  OrcFightVisitor();
  bool Fight(const npcs::Orc &orc) const override;
  bool Fight(const npcs::Brigand &brigand) const override;
  bool Fight(const npcs::Werewolf &werewolf) const override;
};
} // namespace fight_visitors
} // namespace fight_system
