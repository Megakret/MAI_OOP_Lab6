#pragma once

#include <string>
#include<memory>

#include<NPCs/NPC.hpp>

namespace npcs {
const std::string kOrcName = "Orc";
const std::string kBrigandName = "Brigand";
const std::string kWerewolfName = "Werewolf";
const std::string kUnknownName = "Unknown npc";
std::string GetTypename(std::shared_ptr<NPC> npc);
} // namespace npcs
