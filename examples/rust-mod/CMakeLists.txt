cmake_minimum_required(VERSION 3.21)

project(GeodeRustMod VERSION 1.0.0 LANGUAGES C)

add_library(GeodeRustMod SHARED entry.c)
execute_process(COMMAND cargo build --release WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

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
target_link_libraries(GeodeRustMod geode_interop)

# Link the compiled Rust static library
target_link_libraries(GeodeRustMod ${CMAKE_CURRENT_SOURCE_DIR}/target/release/rust_mod.lib)
target_link_libraries(GeodeRustMod ntdll.lib Ws2_32.lib Userenv.lib Bcrypt.lib)