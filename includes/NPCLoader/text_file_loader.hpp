#pragma once

#include<stdexcept>

#include <NPCLoader/NPCLoader.hpp>
#include <NPCs/NPC.hpp>

namespace npc_loader {

class UnknownTypeException: std::domain_error{
public:
	UnknownTypeException(const std::string& got_type): std::domain_error(
		"Got unknown type: " + got_type
	){}
};

class TextFileLoader : public NPCLoader {
public:
	TextFileLoader(const std::string& filename);
  void Save(const std::map<std::string, std::shared_ptr<npcs::NPC>>
                &npc_tracker) override;
  std::map<std::string, std::shared_ptr<npcs::NPC>> Load() override;
private:
	std::string filename_;
};
} // namespace npc_loader
