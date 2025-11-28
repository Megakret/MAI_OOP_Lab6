#include <gtest/gtest.h>

#include <npc_factory/npc_factory.hpp>

class NPCFactoryTest : public ::testing::Test {
protected:
  npc_factory::NPCFactory factory_;
};
bool ComparePoints(npcs::Point a, npcs::Point b) {
  return a.x == b.x && a.y == b.y;
}
TEST_F(NPCFactoryTest, OrcCreationTest) {
  factory_.CreateOrc("Rookie", {0, 0});
  factory_.CreateOrc("Sergeant orc", {1, 1});
  factory_.CreateOrc("Leader orc", {2, 2});

  auto npcs = factory_.GetNPCs();
  auto rookie(npcs["Rookie"]);
  auto sergeant(npcs["Sergeant orc"]);
  auto leader(npcs["Leader orc"]);
  EXPECT_EQ(rookie->GetName(), "Rookie");
  EXPECT_TRUE(ComparePoints(rookie->GetCoords(), {0, 0}));

  EXPECT_EQ(sergeant->GetName(), "Sergeant orc");
  EXPECT_TRUE(ComparePoints(sergeant->GetCoords(), {1, 1}));

  EXPECT_EQ(leader->GetName(), "Leader orc");
  EXPECT_TRUE(ComparePoints(leader->GetCoords(), {2, 2}));
}

TEST_F(NPCFactoryTest, OrcRemovalTest) {
  factory_.CreateOrc("Rookie", {0, 0});
  factory_.CreateOrc("Strong", {1, 1});

  factory_.RemoveNPC("Rookie");
  auto npcs = factory_.GetNPCs();
  EXPECT_EQ(npcs.find("Rookie"), npcs.end());
  EXPECT_NE(npcs.find("Strong"), npcs.end());
}

TEST_F(NPCFactoryTest, UniqueException) {
  factory_.CreateOrc("Rookie", {0, 0});
  EXPECT_THROW(factory_.CreateOrc("Rookie", {0, 0}),
               npc_factory::UniqueNameException);
}
TEST_F(NPCFactoryTest, NPCDoesntExistException) {
  factory_.CreateOrc("Rookie", {0, 0});
  EXPECT_THROW(factory_.RemoveNPC("Noone"),
               npc_factory::NPCDoesntExistException);
}
