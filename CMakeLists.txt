cmake_minimum_required(VERSION 3.16)

project(Gomoku)

if(NOT CMAKE_BUILD_TYPE)
    message(FATAL_ERROR "Missing CMAKE_BUILD_TYPE, set to Debug or Release")
endif()

include(GNUInstallDirs)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_FLAGS "-Wall -Werror")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

#include(ProcessorCount)
#ProcessorCount(CPU_CORES)
#message(STATUS "Processor Count: ${CPU_CORES}")

add_subdirectory(src)