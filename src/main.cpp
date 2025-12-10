#include <memory>

#include <NPCLoader/text_file_loader.hpp>
#include <fight_system/fight_manager.hpp>
#include <fight_system/fight_observers/cout_observer.hpp>
#include <fight_system/fight_observers/log_observer.hpp>
#include <npc_factory/npc_factory.hpp>

const std::string kSaveName = "save.txt";
const std::string kLogName = "fighting_scroll.log";

int main() {
  // Dependency injection
  auto loader = std::make_unique<npc_loader::TextFileLoader>(kSaveName);
  npc_factory::NPCFactory factory(std::move(loader));
  auto cout_observer =
      std::make_shared<fight_system::fight_observers::CoutObserver>();
  auto log_observer =
      std::make_shared<fight_system::fight_observers::LogObserver>(kLogName);
  fight_system::FightManager manager(factory, {cout_observer, log_observer});

  // Instantiation
  factory.Load();

  manager.StartFighting(3);
}
