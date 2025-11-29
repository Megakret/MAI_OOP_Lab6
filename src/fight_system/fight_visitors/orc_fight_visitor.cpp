#include <fight_system/fight_visitors/orc_fight_visitor.hpp>

#include <NPCs/Brigand.hpp>
#include <NPCs/Orc.hpp>
#include <NPCs/Werewolf.hpp>

namespace fight_system::fight_visitors {
OrcFightVisitor::OrcFightVisitor() = default;
bool OrcFightVisitor::Fight(const npcs::Orc &orc) const { return false; }
bool OrcFightVisitor::Fight(const npcs::Brigand &brigand) const { return true; }
bool OrcFightVisitor::Fight(const npcs::Werewolf &werewolf) const { return false; }
} // namespace fight_system::fight_visitors
