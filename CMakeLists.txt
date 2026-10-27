
cmake_minimum_required(VERSION 3.20)

project(GamingEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL2 CONFIG REQUIRED)

add_executable(GamingEngine Main.cpp)

# Main.cpp intentionally supplies its own no-argument main().  Prevent SDL.h
# from redirecting it to SDL_main, whose SDL2main ABI requires argc/argv.
target_compile_definitions(GamingEngine PRIVATE SDL_MAIN_HANDLED)
target_link_libraries(GamingEngine PRIVATE SDL2::SDL2)

# Keep the matching SDL2 runtime beside the executable for every configuration.
add_custom_command(TARGET GamingEngine POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:SDL2::SDL2>
            $<TARGET_FILE_DIR:GamingEngine>
    VERBATIM
)

