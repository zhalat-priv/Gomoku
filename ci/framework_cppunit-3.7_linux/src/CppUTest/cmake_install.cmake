# Install script for directory: /home/zhalat/Downloads/cppunitSrc/cpputest/src/CppUTest

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/CppUTest" TYPE FILE FILES
    "/home/zhalat/Downloads/cppunitSrc/cpputest/include/CppUTest/CommandLineArguments.h"
    "/home/zhalat/Downloads/cppunitSrc/cpputest/include/CppUTest/PlatformSpecificFunctions.h"
    "/home/zhalat/Downloads/cppunitSrc/cpputest/include/CppUTest/TestMemoryAllocator.h"
    "/home/zhalat/Downloads/cppunitSrc/cpputest/include/CppUTest/CommandLineTestRunner.h"
    "/home/zhalat/Downloads/cppunitSrc/cpputest/include/CppUTest/PlatformSpecificFunctions_c.h"
    "/home/zhalat/Downloads/cppunitSrc/cpputest/include/CppUTest/TestOutput.h"
    "/home/zhalat/Downloads/cppunitSrc/cpputest/include/CppUTest/CppUTestConfig.h"
    "/home/zhalat/Downloads/cppunitSrc/cpputest/include/CppUTest/SimpleString.h"
    "/home/zhalat/Downloads/cppunitSrc/cpputest/include/CppUTest/TestPlugin.h"
    "/home/zhalat/Downloads/cppunitSrc/cpputest/include/CppUTest/JUnitTestOutput.h"
    "/home/zhalat/Downloads/cppunitSrc/cpputest/include/CppUTest/TeamCityTestOutput.h"
    "/home/zhalat/Downloads/cppunitSrc/cpputest/include/CppUTest/StandardCLibrary.h"
    "/home/zhalat/Downloads/cppunitSrc/cpputest/include/CppUTest/TestRegistry.h"
    "/home/zhalat/Downloads/cppunitSrc/cpputest/include/CppUTest/MemoryLeakDetector.h"
    "/home/zhalat/Downloads/cppunitSrc/cpputest/include/CppUTest/TestFailure.h"
    "/home/zhalat/Downloads/cppunitSrc/cpputest/include/CppUTest/TestResult.h"
    "/home/zhalat/Downloads/cppunitSrc/cpputest/include/CppUTest/MemoryLeakDetectorMallocMacros.h"
    "/home/zhalat/Downloads/cppunitSrc/cpputest/include/CppUTest/TestFilter.h"
    "/home/zhalat/Downloads/cppunitSrc/cpputest/include/CppUTest/TestTestingFixture.h"
    "/home/zhalat/Downloads/cppunitSrc/cpputest/include/CppUTest/MemoryLeakDetectorNewMacros.h"
    "/home/zhalat/Downloads/cppunitSrc/cpputest/include/CppUTest/TestHarness.h"
    "/home/zhalat/Downloads/cppunitSrc/cpputest/include/CppUTest/Utest.h"
    "/home/zhalat/Downloads/cppunitSrc/cpputest/include/CppUTest/MemoryLeakWarningPlugin.h"
    "/home/zhalat/Downloads/cppunitSrc/cpputest/include/CppUTest/TestHarness_c.h"
    "/home/zhalat/Downloads/cppunitSrc/cpputest/include/CppUTest/UtestMacros.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/zhalat/Downloads/cppunitSrc/build/src/CppUTest/libCppUTest.a")
endif()

