add_library(NPC_lib NPC.cpp)
target_include_directories(NPC_lib PUBLIC ${INCLUDES})

add_library(Orc_lib Orc.cpp)
target_link_libraries(Orc_lib NPC_lib)
