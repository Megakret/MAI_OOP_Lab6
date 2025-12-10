#include <npc_factory/npc_factory.hpp>

#include <iostream>
#include <memory>

#include <NPCs/Brigand.hpp>
#include <NPCs/NPC.hpp>
#include <NPCs/NPCFormatting.hpp>
#include <NPCs/Orc.hpp>
#include <NPCs/Werewolf.hpp>

namespace npc_factory {

const std::string kOrcName = "Orc";
const std::string kBrigandName = "Brigand";
const std::string kWerewolfName = "Werewolf";
const std::string kUnknownName = "Unknown npc";
bool ValidateName(const std::string &name) {
  for (char c : name) {
    if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) {
      return false;
    }
  }
  return true;
}
NPCFactory::NPCFactory() : loader_(nullptr) {}
NPCFactory::NPCFactory(std::unique_ptr<npc_loader::NPCLoader> &&loader)
    : loader_(std::move(loader)) {}
std::shared_ptr<npcs::Orc> NPCFactory::CreateOrc(const std::string &name,
                                                 npcs::Point coords) {
	if(!ValidateName(name)){
		throw WrongFormatException(name);
	}
  if (npcs_.find(name) != npcs_.end()) {
    throw UniqueNameException(name);
  }
  auto orc = std::make_shared<npcs::Orc>(name, coords);
  npcs_[name] = orc;
  return orc;
}
std::shared_ptr<npcs::Brigand>
NPCFactory::CreateBrigand(const std::string &name, npcs::Point coords) {
	if(!ValidateName(name)){
		throw WrongFormatException(name);
	}
  if (npcs_.find(name) != npcs_.end()) {
    throw UniqueNameException(name);
  }
  auto brigand = std::make_shared<npcs::Brigand>(name, coords);
  npcs_[name] = brigand;
  return brigand;
}
std::shared_ptr<npcs::Werewolf>
NPCFactory::CreateWerewolf(const std::string &name, npcs::Point coords) {
	if(!ValidateName(name)){
		throw WrongFormatException(name);
	}
  if (npcs_.find(name) != npcs_.end()) {
    throw UniqueNameException(name);
  }
  auto werewolf = std::make_shared<npcs::Werewolf>(name, coords);
  npcs_[name] = werewolf;
  return werewolf;
}
void NPCFactory::RemoveNPC(const std::string &name) {
  auto it = npcs_.find(name);
  if (it == npcs_.end()) {
    throw NPCDoesntExistException(name);
  }
  npcs_.erase(it);
}
const std::map<std::string, std::shared_ptr<npcs::NPC>> &
NPCFactory::GetNPCs() const {
  return npcs_;
}
void NPCFactory::Save() { loader_->Save(npcs_); }
void NPCFactory::Load() { npcs_ = loader_->Load(); }
void NPCFactory::Print() const {
  for (auto &[name, npc] : npcs_) {
    auto coords = npc->GetCoords();
    std::cout << "NPC type: " << npcs::GetTypename(npc)
              << " Name: " << npc->GetName() << " Coordinates: (" << coords.x
              << ", " << coords.y << ")\n";
  }
}
}; // namespace npc_factory
