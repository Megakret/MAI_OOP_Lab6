#include <NPCs/NPCFormatting.hpp>

#include<NPCs/Orc.hpp>
#include<NPCs/Brigand.hpp>
#include<NPCs/Werewolf.hpp>

std::string npcs::GetTypename(std::shared_ptr<NPC> npc) {
  if (std::dynamic_pointer_cast<npcs::Orc>(npc) != nullptr) {
    return npcs::kOrcName;
  } else if (std::dynamic_pointer_cast<npcs::Brigand>(npc) != nullptr) {
    return npcs::kBrigandName;
  } else if (std::dynamic_pointer_cast<npcs::Werewolf>(npc) != nullptr) {
    return npcs::kWerewolfName;
  } else {
    return npcs::kUnknownName;
  }
}
