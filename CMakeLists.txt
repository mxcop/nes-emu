cmake_minimum_required(VERSION 3.15)
project(nes-emu)

# C++ standard version
set(CMAKE_CXX_STANDARD 20 CACHE STRING "" FORCE)

# Executable target
add_executable(nes-emu)
set_target_properties(nes-emu PROPERTIES OUTPUT_NAME ${CMAKE_PROJECT_NAME})

# Add compiler (debug & release) definitions
target_compile_definitions(nes-emu PRIVATE $<$<CONFIG:Debug>:DEBUG=1>)
target_compile_definitions(nes-emu PRIVATE $<$<CONFIG:Release>:NDEBUG=1>)

# Include directories & pre-compiled header
target_include_directories(nes-emu PRIVATE "src/")
target_precompile_headers(nes-emu PRIVATE "src/pch.hh")

# Glob all source files
file(GLOB_RECURSE src "src/*.cc")
target_sources(nes-emu PRIVATE ${src})
