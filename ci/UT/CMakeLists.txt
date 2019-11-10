cmake_minimum_required( VERSION 2.6 )

project( ci )

set( ${PROJECT_NAME_UPPERCASE}_CXX_FLAGS -mno-align-double )

add_definitions( 
    -DUNIT_TEST
    -DGOMOKUBOARDTEST #this define is for unblock test in main().
)

add_definitions( -std=gnu++11 )

SET( CMAKE_BUILD_TYPE Debug )

set( CMAKE_PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR} )

# Set path directories
set( GOMOKUGAME_SRC "${CMAKE_PROJECT_ROOT}/../../src/Sources" )
set( GOMOKUGAME_INC "${CMAKE_PROJECT_ROOT}/../../src/Headers" )
set( UT_GOMOKUGAME_SRC "${CMAKE_PROJECT_ROOT}" )
set( UT_GOMOKUGAME_INC "${CMAKE_PROJECT_ROOT}" )
set( CPPUNIT_INC "${CMAKE_PROJECT_ROOT}/../framework_cppunit-3.7_linux/include" )
set( CPPUNIT_LIB "${CMAKE_PROJECT_ROOT}/../framework_cppunit-3.7_linux/src/CppUTest" )
set( STUBS_GLOBAL "${CMAKE_PROJECT_ROOT}/StubsGlobal" )

# Define Sources
set( ${PROJECT_NAME_UPPERCASE}_SRC
    # Main file
    "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp"
    # Unit under test
    "${GOMOKUGAME_SRC}/GomokuBoard.cpp"
    # Unit test
    "${UT_GOMOKUGAME_SRC}/GomokuBoardTest/GomokuBoardTest.cpp"
    # Support classes
    "${GOMOKUGAME_SRC}/DataContainers/Graph.cpp"
    # Stubs
    "${STUBS_GLOBAL}/StubBoardIterator.cpp"
    "${STUBS_GLOBAL}/StubGraphIterator.cpp"
)

# Define the path to the includes
set( ${PROJECT_NAME_UPPERCASE}_INCLUDE
    "${CPPUNIT_INC}"
    "${GOMOKUGAME_INC}"
	"${GOMOKUGAME_INC}/DataContainers"
    "${UT_GOMOKUGAME_INC}"
)

include_directories( ${${PROJECT_NAME_UPPERCASE}_INCLUDE} )
add_executable( ci ${${PROJECT_NAME_UPPERCASE}_SRC} )

#External library:
add_library( libMyCppUnitStaticLibrary STATIC IMPORTED )
set_target_properties( libMyCppUnitStaticLibrary PROPERTIES IMPORTED_LOCATION "${CPPUNIT_LIB}/libMyCppUnitStaticLibrary.a" )
TARGET_LINK_LIBRARIES( ci libMyCppUnitStaticLibrary )