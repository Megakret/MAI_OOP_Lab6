add_subdirectory(NPCs)
add_subdirectory(npc_factory)
add_subdirectory(fight_system)
add_subdirectory(NPCLoader)

add_executable(main main.cpp)
target_include_directories(main PUBLIC ${INCLUDES})
target_link_libraries(main NPCFactory_lib fight_manager_lib cout_observer_lib log_observer_lib text_file_loader_lib)
