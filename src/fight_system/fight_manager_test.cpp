#include <gtest/gtest.h>

#include <fight_system/fight_manager.hpp>
#include <fight_system/fight_observers/in_memory_observer.hpp>
#include <npc_factory/npc_factory.hpp>

class FightManagerTest : public ::testing::Test {
protected:
  FightManagerTest() : factory(), observer(std::make_shared<fight_system::fight_observers::InMemoryObserver>()), manager(factory, {observer}) {}
  npc_factory::NPCFactory factory;
  std::shared_ptr<fight_system::fight_observers::InMemoryObserver> observer;
  fight_system::FightManager manager;
};

TEST_F(FightManagerTest, OrcVsBrigand) {
  factory.CreateOrc("Orc", {0, 0});
  factory.CreateBrigand("Brigand", {1, 0});
  manager.StartFighting(2);

  EXPECT_EQ(observer->GetWinner(0), "Orc");
}

TEST_F(FightManagerTest, WerewolfVsBrigand) {
  factory.CreateWerewolf("Werewolf", {0, 0});
  factory.CreateBrigand("Brigand", {1, 0});
  manager.StartFighting(2);

  bool has_brigand = false;
  bool has_werewolf = false;
  EXPECT_EQ(observer->GetLength(), 2);
  for (std::size_t i = 0; i < observer->GetLength(); ++i) {
    if (observer->GetWinner(i) == "Werewolf") {
      has_werewolf = true;
    }
    if (observer->GetWinner(i) == "Brigand") {
      has_brigand = true;
    }
  }
  EXPECT_TRUE(has_brigand);
  EXPECT_TRUE(has_werewolf);
}

TEST_F(FightManagerTest, OutOfReach) {
  factory.CreateWerewolf("Werewolf", {0, 0});
  factory.CreateBrigand("Brigand", {100, 0});
  manager.StartFighting(1);
  EXPECT_EQ(observer->GetLength(), 0);
}

TEST_F(FightManagerTest, Friendly) {
	factory.CreateWerewolf("Werewolf", {0,0});
	factory.CreateOrc("Orc", {1,0});
	manager.StartFighting(2);

	EXPECT_EQ(observer->GetLength(), 0);
}
TEST_F(FightManagerTest, DeadManTellNoTales){ //Checking that dead npcs cant fight
	factory.CreateWerewolf("Werewolf", {1,0});
	factory.CreateBrigand("ABrigand", {1,1});
	factory.CreateOrc("AOrc", {1,2});
	
	manager.StartFighting(2);

	EXPECT_EQ(observer->GetLength(), 1);
}
