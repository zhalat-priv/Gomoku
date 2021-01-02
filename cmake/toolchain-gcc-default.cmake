#----------------------------------------------------------------------------------------------------------------------#
#       Copyright       SLabs 2016
#       Project:        embedded-utils
#       Creation date:  29/07/19
#       Toolchain file for embedded-utils.
#----------------------------------------------------------------------------------------------------------------------#
cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

include(${CMAKE_CURRENT_LIST_DIR}/variables.cmake)

if("$ENV{DEFAULT_TOOLCHAIN_PATH}" STREQUAL "")
    message(FATAL_ERROR "env variable DEFAULT_TOOLCHAIN_PATH must be defined")
endif()

set(GCC_PREFIX          "")
set(TOOLCHAIN_PATH      "$ENV{DEFAULT_TOOLCHAIN_PATH}")

if(CMAKE_HOST_WIN32)
    set(EXTENSION ".exe")
elseif(CMAKE_HOST_UNIX)
    set(EXTENSION "")
else()
    message(FATAL_ERROR "Host system not supported!")
endif()

set(CMD_GCC     "${TOOLCHAIN_PATH}/${GCC_PREFIX}gcc${EXTENSION}")
set(CMD_GXX     "${TOOLCHAIN_PATH}/${GCC_PREFIX}g++${EXTENSION}")
set(CMD_OBJDUMP "${TOOLCHAIN_PATH}/${GCC_PREFIX}objdump${EXTENSION}")
set(CMD_OBJCOPY "${TOOLCHAIN_PATH}/${GCC_PREFIX}objcopy${EXTENSION}")
set(CMD_SIZE    "${TOOLCHAIN_PATH}/${GCC_PREFIX}size${EXTENSION}")
#set(CMD_LINK    "${TOOLCHAIN_PATH}/${GCC_PREFIX}ld${EXTENSION}")

set(CMAKE_SYSTEM_NAME Generic)

set(CMAKE_C_COMPILER           ${CMD_GCC})
set(CMAKE_CXX_COMPILER         ${CMD_GXX})
set(CMAKE_ASM_COMPILER         ${CMD_GCC})
#set(CMAKE_CXX_LINK_EXECUTABLE  ${CMD_LINK})

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)