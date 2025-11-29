#include <fight_system/fight_visitors/brigand_fight_visitor.hpp>

#include <NPCs/Brigand.hpp>
#include <NPCs/Orc.hpp>
#include <NPCs/Werewolf.hpp>

namespace fight_system::fight_visitors {
BrigandFightVisitor::BrigandFightVisitor() = default;
bool BrigandFightVisitor::Fight(const npcs::Orc &orc) const { return false; }
bool BrigandFightVisitor::Fight(const npcs::Brigand &brigand) const { return false; }
bool BrigandFightVisitor::Fight(const npcs::Werewolf &werewolf) const { return true; }
} // namespace fight_system::fight_visitors
