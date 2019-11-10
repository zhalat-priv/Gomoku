# Install script for directory: /home/zhalat/Downloads/cppunitSrc/cpputest/src/CppUTestExt

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "RelWithDebInfo")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/CppUTestExt" TYPE FILE FILES
    "/home/zhalat/Downloads/cppunitSrc/cpputest/include/CppUTestExt/CodeMemoryReportFormatter.h"
    "/home/zhalat/Downloads/cppunitSrc/cpputest/include/CppUTestExt/IEEE754ExceptionsPlugin.h"
    "/home/zhalat/Downloads/cppunitSrc/cpputest/include/CppUTestExt/MemoryReportAllocator.h"
    "/home/zhalat/Downloads/cppunitSrc/cpputest/include/CppUTestExt/MockExpectedCall.h"
    "/home/zhalat/Downloads/cppunitSrc/cpputest/include/CppUTestExt/MockCheckedExpectedCall.h"
    "/home/zhalat/Downloads/cppunitSrc/cpputest/include/CppUTestExt/MockExpectedCallsList.h"
    "/home/zhalat/Downloads/cppunitSrc/cpputest/include/CppUTestExt/MockSupportPlugin.h"
    "/home/zhalat/Downloads/cppunitSrc/cpputest/include/CppUTestExt/MemoryReportFormatter.h"
    "/home/zhalat/Downloads/cppunitSrc/cpputest/include/CppUTestExt/MockFailure.h"
    "/home/zhalat/Downloads/cppunitSrc/cpputest/include/CppUTestExt/MockSupport.h"
    "/home/zhalat/Downloads/cppunitSrc/cpputest/include/CppUTestExt/MockSupport_c.h"
    "/home/zhalat/Downloads/cppunitSrc/cpputest/include/CppUTestExt/GMock.h"
    "/home/zhalat/Downloads/cppunitSrc/cpputest/include/CppUTestExt/GTest.h"
    "/home/zhalat/Downloads/cppunitSrc/cpputest/include/CppUTestExt/MemoryReporterPlugin.h"
    "/home/zhalat/Downloads/cppunitSrc/cpputest/include/CppUTestExt/OrderedTest.h"
    "/home/zhalat/Downloads/cppunitSrc/cpputest/include/CppUTestExt/GTestConvertor.h"
    "/home/zhalat/Downloads/cppunitSrc/cpputest/include/CppUTestExt/MockActualCall.h"
    "/home/zhalat/Downloads/cppunitSrc/cpputest/include/CppUTestExt/MockCheckedActualCall.h"
    "/home/zhalat/Downloads/cppunitSrc/cpputest/include/CppUTestExt/MockNamedValue.h"
    "/home/zhalat/Downloads/cppunitSrc/cpputest/include/CppUTestExt/MockSupport.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/zhalat/Downloads/cppunitSrc/build/src/CppUTestExt/libCppUTestExt.a")
endif()

