cmake_minimum_required(VERSION 4.0..4.5)
project(rudp_protocol
	LANGUAGES CXX C
	VERSION 0.0.1
	DESCRIPTION "Multi-environment transport protocol living purely in layer 4 of the OSI model")

if (NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release CACHE STRING "CMake build type" FORCE)
endif()
message(STATUS "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")

# Dummy library to apply shared project settings across targets.
add_library(cxx_setup INTERFACE)
target_compile_options(cxx_setup INTERFACE
    $<$<CXX_COMPILER_ID:GNU,Clang>:-Wall -Wextra -Wpedantic>
    $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX /permissive- /utf-8>)
target_compile_features(cxx_setup INTERFACE cxx_std_20)

add_subdirectory(external)
add_subdirectory(${PROJECT_NAME})
add_subdirectory(executables)
