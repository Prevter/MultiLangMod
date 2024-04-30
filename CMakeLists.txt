cmake_minimum_required(VERSION 3.28)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_OSX_ARCHITECTURES "x86_64")
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

project(geode_interop)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Xclang -fcxx-exceptions)
endif()

option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

file(GLOB_RECURSE GEODE_INTEROP_SOURCES CONFIGURE_DEPENDS src/*.cpp)

if (BUILD_SHARED_LIBS)
    add_library(geode_interop SHARED ${GEODE_INTEROP_SOURCES})
    target_compile_definitions(geode_interop PRIVATE GEODE_INTEROP_SHARED)

    if (WIN32)
        target_compile_definitions(geode_interop PRIVATE GEODE_INTEROP_EXPORTS)
    endif()
else()
    add_library(geode_interop STATIC ${GEODE_INTEROP_SOURCES})
endif()
target_include_directories(geode_interop PUBLIC ${CMAKE_SOURCE_DIR}/include)

option(EXAMPLE_LANGUAGE "Choose the language for the example" "cpp")

if (EXAMPLE_LANGUAGE STREQUAL "cpp")
    add_subdirectory(examples/cpp-mod)
elseif (EXAMPLE_LANGUAGE STREQUAL "c")
    add_subdirectory(examples/c-mod)
elseif (EXAMPLE_LANGUAGE STREQUAL "asm")
    add_subdirectory(examples/asm-mod)
elseif (EXAMPLE_LANGUAGE STREQUAL "rust")
    add_subdirectory(examples/rust-mod)
else()
    message(FATAL_ERROR "Unknown example language: ${EXAMPLE_LANGUAGE}")
endif()

if(NOT TARGET geode-sdk)
    if (NOT DEFINED ENV{GEODE_SDK})
        message(FATAL_ERROR "Unable to find Geode SDK! Please define GEODE_SDK environment variable to point to Geode")
    else()
        message(STATUS "Found Geode: $ENV{GEODE_SDK}")
    endif()
    add_subdirectory($ENV{GEODE_SDK} ${CMAKE_CURRENT_BINARY_DIR}/geode)
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE geode-sdk)