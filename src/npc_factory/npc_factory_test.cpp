#include <gtest/gtest.h>

#include <npc_factory/npc_factory.hpp>
#include <NPCLoader/text_file_loader.hpp>

class NPCFactoryTest : public ::testing::Test {
protected:
  npc_factory::NPCFactory factory_;
};
class NPCLoadingTest: public ::testing::Test{
protected:
	NPCLoadingTest(): factory1_(std::make_unique<npc_loader::TextFileLoader>("test.txt")),factory2_(std::make_unique<npc_loader::TextFileLoader>("test.txt")) {}
npc_factory::NPCFactory factory1_;
npc_factory::NPCFactory factory2_;
};
const float kPrecision = 1e-5;
bool ComparePoints(npcs::Point a, npcs::Point b) {
	return std::abs(a.x - b.x) <= kPrecision && std::abs(a.y - b.y) <= kPrecision;
}
TEST_F(NPCFactoryTest, OrcCreationTest) {
  factory_.CreateOrc("Rookie", {0, 0});
  factory_.CreateOrc("SergeantOrc", {1, 1});
  factory_.CreateOrc("LeaderOrc", {2, 2});

  auto npcs = factory_.GetNPCs();
  auto rookie(npcs["Rookie"]);
  auto sergeant(npcs["SergeantOrc"]);
  auto leader(npcs["LeaderOrc"]);
  EXPECT_EQ(rookie->GetName(), "Rookie");
  EXPECT_TRUE(ComparePoints(rookie->GetCoords(), {0, 0}));

  EXPECT_EQ(sergeant->GetName(), "SergeantOrc");
  EXPECT_TRUE(ComparePoints(sergeant->GetCoords(), {1, 1}));

  EXPECT_EQ(leader->GetName(), "LeaderOrc");
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

TEST_F(NPCLoadingTest, SaveAndLoad){
	factory1_.CreateOrc("Orc", {0,0});
	factory1_.CreateBrigand("Brigand", {0,0});
	factory1_.CreateWerewolf("Werewolf", {0,0});

	factory1_.Save();
	factory2_.Load();
	auto factory1_npcs = factory1_.GetNPCs();
	auto factory2_npcs = factory2_.GetNPCs();
	for(auto&[name, npc]: factory1_npcs){
		auto npc2 = factory2_npcs[name];
		EXPECT_EQ(npc->GetName(), npc2->GetName());
		ComparePoints(npc->GetCoords(), npc2->GetCoords());
		EXPECT_EQ(typeid(npc.get()), typeid(npc2.get()));
	}
}
