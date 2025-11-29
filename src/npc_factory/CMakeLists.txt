add_library(NPCFactory_lib npc_factory.cpp)
target_include_directories(NPCFactory_lib PUBLIC ${INCLUDES})
target_link_libraries(NPCFactory_lib Orc_lib Werewolf_lib Brigand_lib)

add_executable(NPCFactory_test npc_factory_test.cpp)
target_link_libraries(NPCFactory_test NPCFactory_lib GTest::gtest_main)
