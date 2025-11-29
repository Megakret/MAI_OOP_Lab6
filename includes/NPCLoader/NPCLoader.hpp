#pragma once

#include <map>
#include <memory>
#include <string>

#include <NPCs/NPC.hpp>

namespace npc_loader {
class NPCLoader {
public:
  virtual void Save(
      const std::map<std::string, std::shared_ptr<npcs::NPC>> &npc_tracker) = 0;
  virtual std::map<std::string, std::shared_ptr<npcs::NPC>> Load() = 0;
  virtual ~NPCLoader() = default;
};
} // namespace npc_loader
