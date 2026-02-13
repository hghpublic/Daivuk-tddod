target_sources(${target} PRIVATE
    main.cpp
    game.cpp
)
target_include_directories(${target} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# add_subdirectory(components)
add_subdirectory(helpers)
add_subdirectory(systems)