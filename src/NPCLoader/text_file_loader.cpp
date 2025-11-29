#include <NPCLoader/text_file_loader.hpp>

#include <fstream>

#include <NPCs/Brigand.hpp>
#include <NPCs/Orc.hpp>
#include <NPCs/Werewolf.hpp>
#include <npc_factory/npc_factory.hpp>

namespace npc_loader {
const std::string kOrcName = "Orc";
const std::string kBrigandName = "Brigand";
const std::string kWerewolfName = "Werewolf";
const std::string kUnknownName = "Unknown npc";

TextFileLoader::TextFileLoader(const std::string &filename)
    : filename_(filename) {}
void TextFileLoader::Save(
    const std::map<std::string, std::shared_ptr<npcs::NPC>> &npc_tracker) {
  std::ofstream file(filename_);
  for (auto &[name, npc] : npc_tracker) {
    std::string type_name;
    if (std::dynamic_pointer_cast<npcs::Orc>(npc) != nullptr) {
      type_name = kOrcName;
    } else if (std::dynamic_pointer_cast<npcs::Brigand>(npc) != nullptr) {
      type_name = kBrigandName;
    } else if (std::dynamic_pointer_cast<npcs::Werewolf>(npc) != nullptr) {
      type_name = kWerewolfName;
    } else {
      type_name = kUnknownName;
    }
    auto coords = npc->GetCoords();
    file << type_name << ' ' << npc->GetName() << ' ' << coords.x << ' '
         << coords.y << '\n';
  }
}
std::map<std::string, std::shared_ptr<npcs::NPC>> TextFileLoader::Load() {
  std::ifstream file(filename_);
  std::map<std::string, std::shared_ptr<npcs::NPC>> npc_tracker;
  while (!file.eof()) {
    std::string type_name;
    std::string name;
    npcs::Point coords;
    file >> type_name >> name >> coords.x >> coords.y;
		if(file.eof()){
			break;
		}
		if(npc_tracker.contains(name)){
			throw npc_factory::UniqueNameException(name);
		}
    if (type_name == kOrcName) {
      npc_tracker.emplace(name, std::make_shared<npcs::Orc>(name, coords));
    } else if (type_name == kBrigandName) {
      npc_tracker.emplace(name, std::make_shared<npcs::Brigand>(name, coords));
    } else if (type_name == kWerewolfName) {
      npc_tracker.emplace(name, std::make_shared<npcs::Werewolf>(name, coords));
    }else{
			throw UnknownTypeException(type_name);	
		}
  }
	return npc_tracker;
}
}; // namespace npc_loader
