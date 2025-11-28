#pragma once

#include<NPCs/NPC.hpp>

namespace npc_loader {
class NPCLoader {
public:
	virtual void Save(const std::map<std::string, std::unique_ptr<npcs::NPC>>& npc_tracker) = 0;
	virtual std::map<std::string, std::unique_ptr<npcs::NPC>> Load() = 0;
};
} // namespace npc_loader
