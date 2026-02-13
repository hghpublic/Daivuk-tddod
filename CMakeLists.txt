cmake_minimum_required(VERSION 3.30.0)

project(tddod LANGUAGES CXX)


set(target tddod)
add_executable(${target})
target_compile_features(${target} PRIVATE cxx_std_26)

add_subdirectory(src)

find_package(SDL3 CONFIG REQUIRED)
target_link_libraries(${target} PRIVATE SDL3::SDL3)
find_package(Stb REQUIRED)
target_include_directories(${target} PRIVATE ${Stb_INCLUDE_DIR})
find_package(gl3w CONFIG REQUIRED)
target_link_libraries(${target} PRIVATE unofficial::gl3w::gl3w)
find_package(EnTT CONFIG REQUIRED)
target_link_libraries(${target} PRIVATE EnTT::EnTT)

# copy assets

add_custom_command(TARGET ${target} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory 
        ${CMAKE_CURRENT_SOURCE_DIR}/assets
        $<TARGET_FILE_DIR:${target}>/assets)