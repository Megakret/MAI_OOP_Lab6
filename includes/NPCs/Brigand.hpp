#pragma once

#include <NPCs/NPC.hpp>
#include <fight_system/fight_visitors/brigand_fight_visitor.hpp>
#include <fight_system/fight_visitors/fight_visitor.hpp>

namespace npcs {
class Brigand : public NPC {
public:
  Brigand(const std::string &name, Point location);
  bool Fight(const NPC &opponent) const override;
  bool AcceptFight(const fight_system::fight_visitors::FightVisitor
                       &initiator_visitor) const override;

private:
  fight_system::fight_visitors::BrigandFightVisitor fight_visitor_;
};
}; // namespace npcs
