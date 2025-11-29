#include <gtest/gtest.h>

#include <npc_factory/npc_factory.hpp>

class NPCFactoryTest : public ::testing::Test {
protected:
  npc_factory::NPCFactory factory_;
};
const float kPrecision = 1e-5;
bool ComparePoints(npcs::Point a, npcs::Point b) {
	return std::abs(a.x - b.x) <= kPrecision && std::abs(a.y - b.y) <= kPrecision;
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
TEST_F(NPCFactoryTest, DifferentMobs) {
  factory_.CreateOrc("Orc", {0, 0});
  factory_.CreateBrigand("Brigand", {1, 1});
  factory_.CreateWerewolf("Werewolf", {2, 2});

  auto npcs = factory_.GetNPCs();
  auto orc = npcs["Orc"];
  auto brigand = npcs["Brigand"];
  auto werewolf = npcs["Werewolf"];

  EXPECT_EQ(orc->GetName(), "Orc");
  EXPECT_EQ(brigand->GetName(), "Brigand");
  EXPECT_EQ(werewolf->GetName(), "Werewolf");
}
