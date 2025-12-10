add_library(orc_fight_visitor_lib orc_fight_visitor.cpp)
target_include_directories(orc_fight_visitor_lib PUBLIC ${INCLUDES})
add_library(brigand_fight_visitor_lib brigand_fight_visitor.cpp)
target_include_directories(brigand_fight_visitor_lib PUBLIC ${INCLUDES})
add_library(werewolf_fight_visitor_lib werewolf_fight_visitor.cpp)
target_include_directories(werewolf_fight_visitor_lib PUBLIC ${INCLUDES})


