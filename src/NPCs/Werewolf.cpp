#include <NPCs/Werewolf.hpp>

#include <NPCs/NPC.hpp>

namespace npcs {

Werewolf::Werewolf(const std::string &name, Point location)
    : NPC(name, location) {}
bool Werewolf::Fight(const NPC &opponent) const {
  return opponent.AcceptFight(fight_visitor_);
}
bool Werewolf::AcceptFight(
    const fight_system::fight_visitors::FightVisitor &initiator_visitor) const {
  return initiator_visitor.Fight(*this);
}
}; // namespace npcs
