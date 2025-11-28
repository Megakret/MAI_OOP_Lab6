#include <memory>

#include <NPCs/NPC.hpp>
#include <NPCs/Orc.hpp>
#include <npc_factory/npc_factory.hpp>

namespace npc_factory {
std::shared_ptr<npcs::Orc> NPCFactory::CreateOrc(const std::string &name,
                                                 npcs::Point coords) {
  if (npcs_.find(name) != npcs_.end()) {
    throw UniqueNameException(name);
  }
  auto orc = std::make_shared<npcs::Orc>(name, coords);
  npcs_[name] = orc;
  return orc;
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
}; // namespace npc_factory
