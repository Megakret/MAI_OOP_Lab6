#include <NPCs/Orc.hpp>

#include <NPCs/NPC.hpp>

namespace npcs {

Orc::Orc(const std::string &name, Point location) : NPC(name, location) {}
bool Orc::Fight(const NPC &opponent) const {
  return opponent.AcceptFight(fight_visitor_);
}
bool Orc::AcceptFight(
    const fight_system::fight_visitors::FightVisitor &initiator_visitor) const {
  return initiator_visitor.Fight(*this);
}
}; // namespace npcs
