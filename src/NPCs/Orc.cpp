#include <NPCs/NPC.hpp>
#include <NPCs/Orc.hpp>
namespace npcs{
Orc::Orc(const std::string& name, Point location): NPC(name, location){}
bool Orc::Fight(const NPC &opponent){
	return true;
}
bool Orc::AcceptFight(const fight_system::fight_visitors::FightVisitor& initiator_visitor){
	return true;
}
};
