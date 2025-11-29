#include <NPCs/Brigand.hpp>

#include <NPCs/NPC.hpp>

namespace npcs {
Brigand::Brigand(const std::string &name, Point location)
    : NPC(name, location) {}
bool Brigand::Fight(const NPC &opponent) const {
  return opponent.AcceptFight(fight_visitor_);
}
bool Brigand::AcceptFight(
    const fight_system::fight_visitors::FightVisitor &initiator_visitor) const {
  return initiator_visitor.Fight(*this);
}
}; // namespace npcs
