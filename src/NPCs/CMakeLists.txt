add_library(NPC_lib NPC.cpp)
target_include_directories(NPC_lib PUBLIC ${INCLUDES})

add_library(Orc_lib Orc.cpp)
target_link_libraries(Orc_lib NPC_lib orc_fight_visitor_lib)

add_library(Brigand_lib Brigand.cpp)
target_link_libraries(Brigand_lib NPC_lib brigand_fight_visitor_lib)

add_library(Werewolf_lib Werewolf.cpp)
target_link_libraries(Werewolf_lib NPC_lib werewolf_fight_visitor_lib)
