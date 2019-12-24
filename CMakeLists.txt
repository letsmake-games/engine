#
# (C) LetsMakeGames 2019
# http://www.letsmake.games
#

cmake_minimum_required(VERSION 3.13)


#
# project configuration #######################################################
#

set(PROJECT_NAME engine)
set(PROJECT_MAJOR 0)
set(PROJECT_MINOR 1)
set(PROJECT_PATCH 0)
set(PROJECT_DESCRIPTION "A modular game engine.")

project(${PROJECT_NAME}
        VERSION ${PROJECT_MAJOR}.${PROJECT_MINOR}.${PROJECT_PATCH}
        DESCRIPTION ${PROJECT_DESCRIPTION}
        LANGUAGES CXX
)

option(BUILD_TESTS "Build the tests" ON)
if(BUILD_TESTS)
    enable_testing()
endif()

#
# includes ####################################################################
#

if(NOT BT_CMAKE_DIR)
    set(BT_CMAKE_DIR ${CMAKE_CURRENT_LIST_DIR}/cmake CACHE STRING "The top level cmake utilities directory")
endif()

# a collection of add_library add_executable and add_test macros to make adding
# targets easier
include("${BT_CMAKE_DIR}/TargetMacros.cmake")

#
# add targets #################################################################
#

add_subdirectory(extern)
add_subdirectory(project)
