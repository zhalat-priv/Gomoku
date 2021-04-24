cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

include(${CMAKE_CURRENT_LIST_DIR}/variables.cmake)

set(CMAKE_SYSTEM_PROCESSOR  x86)
set(triplet                 "")
set(TOOLCHAIN_PATH          /usr/bin)

set(CMAKE_C_COMPILER        "${TOOLCHAIN_PATH}/${triplet}gcc")
set(CMAKE_CXX_COMPILER      "${TOOLCHAIN_PATH}/${triplet}g++")
#set(CMD_OBJDUMP            "${TOOLCHAIN_PATH}/${triplet}objdump")
#set(CMD_OBJCOPY            "${TOOLCHAIN_PATH}/${triplet}objcopy")
#set(CMD_SIZE               "${TOOLCHAIN_PATH}/${triplet}size")
