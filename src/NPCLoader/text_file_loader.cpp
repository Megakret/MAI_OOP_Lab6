#include <NPCLoader/text_file_loader.hpp>

#include <fstream>

#include <NPCs/NPCFormatting.hpp>
#include <NPCs/Brigand.hpp>
#include <NPCs/Orc.hpp>
#include <NPCs/Werewolf.hpp>
#include <npc_factory/npc_factory.hpp>

namespace npc_loader {

TextFileLoader::TextFileLoader(const std::string &filename)
    : filename_(filename) {}
void TextFileLoader::Save(
    const std::map<std::string, std::shared_ptr<npcs::NPC>> &npc_tracker) {
  std::ofstream file(filename_);
  for (auto &[name, npc] : npc_tracker) {
    std::string type_name(npcs::GetTypename(npc));
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
    if (type_name == npcs::kOrcName) {
      npc_tracker.emplace(name, std::make_shared<npcs::Orc>(name, coords));
    } else if (type_name == npcs::kBrigandName) {
      npc_tracker.emplace(name, std::make_shared<npcs::Brigand>(name, coords));
    } else if (type_name == npcs::kWerewolfName) {
      npc_tracker.emplace(name, std::make_shared<npcs::Werewolf>(name, coords));
    }else{
			throw UnknownTypeException(type_name);	
		}
  }
	return npc_tracker;
}
}; // namespace npc_loader
