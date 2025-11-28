#pragma once

#include <fight_system/fight_visitors/fight_visitor.hpp>

namespace fight_system::fight_visitors {
class OrcFightVisitor : public FightVisitor {
public:
	OrcFightVisitor();
  bool Fight(const npcs::Orc &orc) override;
  bool Fight(const npcs::Brigand &brigand) override;
  bool Fight(const npcs::Werewolf &werewolf) override;
};
}; // namespace fight_manager::fight_visitors
