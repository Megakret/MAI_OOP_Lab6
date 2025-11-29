#include <NPCs/Brigand.hpp>
#include <NPCs/Orc.hpp>
#include <NPCs/Werewolf.hpp>
#include <fight_system/fight_visitors/werewolf_fight_visitor.hpp>

namespace fight_system::fight_visitors {
WerewolfFightVisitor::WerewolfFightVisitor() = default;
bool WerewolfFightVisitor::Fight(const npcs::Orc &orc) const { return false; }
bool WerewolfFightVisitor::Fight(const npcs::Brigand &brigand) const { return true; }
bool WerewolfFightVisitor::Fight(const npcs::Werewolf &werewolf) const { return false; }
} // namespace fight_system::fight_visitors
