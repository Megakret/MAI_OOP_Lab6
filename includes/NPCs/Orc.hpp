#pragma once

#include <NPCs/NPC.hpp>
#include <fight_system/fight_visitors/fight_visitor.hpp>
#include <fight_system/fight_visitors/orc_fight_visitor.hpp>

namespace npcs {
class Orc : public NPC {
public:
  Orc(const std::string &name, Point location);
  bool Fight(const NPC &opponent) override;
  bool AcceptFight(const fight_system::fight_visitors::FightVisitor
                       &initiator_visitor) override;

private:
  //fight_system::fight_visitors::OrcFightVisitor fight_visitor_;
};
}; // namespace npcs
