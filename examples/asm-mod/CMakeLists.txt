cmake_minimum_required(VERSION 3.21)

set(CMAKE_ASM_NASM_COMPILER nasm)
# define nasm command syntax
set(CMAKE_ASM_NASM_COMPILE_OBJECT "<CMAKE_ASM_NASM_COMPILER> -f win32 -o <OBJECT> <SOURCE>")

project(GeodeAsmMod VERSION 1.0.0 LANGUAGES C ASM_NASM)
add_library(GeodeAsmMod SHARED entry.c test.asm)

# Include Geode
if (NOT DEFINED ENV{GEODE_SDK})
    message(FATAL_ERROR "Unable to find Geode SDK! Please define GEODE_SDK environment variable to point to Geode")
else()
    message(STATUS "Found Geode: $ENV{GEODE_SDK}")
endif()
add_subdirectory($ENV{GEODE_SDK} ${CMAKE_CURRENT_BINARY_DIR}/geode)
setup_geode_mod(${PROJECT_NAME})

# Include Geode C bindings
if (NOT TARGET geode_interop)
    message(STATUS "Geode C bindings not found, building from source")
    add_subdirectory(../../. geode-interop)
endif()
target_link_libraries(GeodeAsmMod geode_interop)