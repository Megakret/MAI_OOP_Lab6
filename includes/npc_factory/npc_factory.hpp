#pragma once

#include <map>
#include <memory>

#include <NPCs/NPC.hpp>
#include <NPCs/Brigand.hpp>
#include <NPCs/Orc.hpp>
#include <NPCs/Werewolf.hpp>

namespace npc_factory {

class UniqueNameException : std::invalid_argument {
public:
  UniqueNameException(const std::string &name)
      : std::invalid_argument("NPC with name: " + name + " already exists") {}
};

class NPCDoesntExistException : std::invalid_argument {
public:
  NPCDoesntExistException(const std::string &name)
      : std::invalid_argument("NPC with name: " + name + " doesnt exist") {}
};

class NPCFactory {
public:
	std::shared_ptr<npcs::Orc> CreateOrc(const std::string &name, npcs::Point coordinates);
  std::shared_ptr<npcs::Brigand> CreateBrigand(const std::string &name, npcs::Point coordinates);
  std::shared_ptr<npcs::Werewolf> CreateWerewolf(const std::string &name, npcs::Point coordinates);

  void RemoveNPC(const std::string &name);

  void Save();
  void Load();

  void Print() const;

  const std::map<std::string, std::shared_ptr<npcs::NPC>> &GetNPCs() const;

private:
  std::map<std::string, std::shared_ptr<npcs::NPC>> npcs_;
};
} // namespace npc_factory
