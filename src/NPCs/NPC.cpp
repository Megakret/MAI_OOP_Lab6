#include <NPCs/NPC.hpp>

namespace npcs{
NPC::NPC(const std::string &name, Point location): location_(location), name_(name){}
std::string_view NPC::GetName() const{
	return std::string_view(name_);
}
Point NPC::GetCoords() const{
	return location_;
}
NPC::~NPC(){}
};
