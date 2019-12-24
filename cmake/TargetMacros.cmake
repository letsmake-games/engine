#
# LetsMakeGames (c) 2019
# http://www.letsmake.games
#

#
# Require out-of-source builds ################################################
#

file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
if(EXISTS "${LOC_PATH}")
    message(FATAL_ERROR "You cannot build in a source directory (or any directory with a CMakeLists.txt file). Please make a build subdirectory. Feel free to remove CMakeCache.txt and CMakeFiles.")
endif()

#
# Do standard MSCV configurations #############################################
#

include("${CMAKE_CURRENT_LIST_DIR}/msvc.cmake")

#
# shared bt compile options ###################################################
#

if(CMAKE_CXX_COMPILER MATCHES "MSVC")
    set(BT_CXX_FLAGS)
else()
    set(BT_CXX_FLAGS -Wall -fno-rtti)
    set(BT_CXX_BENCH_FLAGS -Wno-unused-variable)
endif()

#
# configure platform defines ##################################################
#

# platform --------------------------------------------------------------------
if(UNIX)
    set(BT_PLATFORM "unix")
    set(BT_PLATFORM_UNIX TRUE)
elseif(WIN32)
    set(BT_PLATFORM "win32")
    set(BT_PLATFORM_WIN32 TRUE)
elseif(APPLE)
    set(BT_PLATFORM "darwin")
    set(BT_PLATFORM_DARWIN TRUE)
elseif(MINGW)
    set(BT_PLATFORM "mingw")
    set(BT_PLATFORM_MINGW TRUE)
elseif(CYGWIN)
    set(BT_PLATFORM "cygwin")
    set(BT_PLATFORM_CYGWIN TRUE)
else()
    set(BT_PLATFORM "other")
    set(BT_PLATFORM_OTHER TRUE)
endif()

# compiler --------------------------------------------------------------------
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    set(BT_GCC TRUE)
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    set(BT_MSVC TRUE)
endif()

# build type ------------------------------------------------------------------
if("${CMAKE_BUILD_TYPE}" STREQUAL "Release" OR "${CMAKE_BUILD_TYPE}" STREQUAL "MinSizeRel")
    set(BT_RELEASE TRUE)
else()
    set(BT_DEBUG TRUE)
endif()

#
# Add library #################################################################
#

function(bt_add_library NAME TYPE)
    set(opts)
    set(args)
    set(margs 
        SOURCES 

        TESTS
        BENCHMARKS

        LIBRARIES 
        PRIVATE_LIBRARIES 
        INTERFACE_LIBRARIES

        INCLUDES 
        PRIVATE_INCLUDES 
        INTERFACE_INCLUDES
    )

    cmake_parse_arguments(ARGS "${opts}" "${args}" "${margs}" ${ARGN})

    add_library(${NAME} ${TYPE} ${ARGS_SOURCES})
    if(NOT ${TYPE} STREQUAL "INTERFACE")
        target_compile_options(${NAME} PRIVATE ${BT_CXX_FLAGS})
        set_property(TARGET ${NAME} PROPERTY CXX_STANDARD 17)
        target_link_libraries(${NAME} PUBLIC ${ARGS_LIBRARIES} PRIVATE ${ARGS_PRIVATE_LIBRARIES} INTERFACE ${ARGS_INTERFACE_LIBRARIES})
        target_include_directories(${NAME} PUBLIC ${ARGS_INCLUDES} PRIVATE ${ARGS_PRIVATE_INCLUDES} INTERFACE ${ARGS_INTERFACE_INCLUDES})
    else()
        target_link_libraries(${NAME} INTERFACE ${ARGS_INTERFACE_LIBRARIES})
        target_include_directories(${NAME} INTERFACE ${ARGS_INTERFACE_INCLUDES})
    endif()
endfunction()

#
# Add executable ##############################################################
#

function(bt_add_executable NAME)
    set(opts)
    set(args)
    set(margs 
        SOURCES 
        TESTS
        BENCHMARKS
        LIBRARIES
    )
    cmake_parse_arguments(ARGS "${opts}" "${args}" "${margs}" ${ARGN})

    add_executable(${NAME} ${ARGS_SOURCES})
    target_compile_options(${NAME} PRIVATE ${BT_CXX_FLAGS})
    set_property(TARGET ${NAME} PROPERTY CXX_STANDARD 17)
    target_link_libraries(${NAME} ${ARGS_LIBRARIES})
endfunction()


#
# Add test ####################################################################
#

function(bt_add_test NAME)
    set(opts)
    set(args)
    set(margs TESTS BENCHMARKS LIBRARIES EXAMPLES)
    cmake_parse_arguments(ARGS "${opts}" "${args}" "${margs}" ${ARGN})

    if(BUILD_TESTS)
        if(BT_TESTING)
            if(ARGS_TESTS)
                set(TEST_NAME Test_${NAME})
                add_executable(${TEST_NAME} ${ARGS_TESTS})
                target_compile_options(${TEST_NAME} PRIVATE ${BT_CXX_FLAGS})
                set_property(TARGET ${TEST_NAME} PROPERTY CXX_STANDARD 20)
                target_link_libraries(${TEST_NAME} ${ARGS_LIBRARIES} gtest gtest_main)
                add_test(${TEST_NAME} ${TEST_NAME})
            endif()
        endif()

        if(BUILD_BENCHMARKS)
            if(ARGS_BENCHMARKS)
                set(BENCH_DIR "${CMAKE_BINARY_DIR}/benchmark")
                file(MAKE_DIRECTORY ${BENCH_DIR})

                set(BENCHMARK_NAME Benchmark_${NAME})
                add_executable(${BENCHMARK_NAME} ${ARGS_BENCHMARKS})
                target_compile_options(${BENCHMARK_NAME} PRIVATE ${BT_CXX_FLAGS} ${BT_CXX_BENCH_FLAGS})
                set_property(TARGET ${BENCHMARK_NAME} PROPERTY CXX_STANDARD 20)
                target_link_libraries(${BENCHMARK_NAME} ${ARGS_LIBRARIES} benchmark benchmark_main)
                set(BENCHOUT_FILE "${BENCH_DIR}/${BENCHMARK_NAME}.json")
                if(EXISTS ${BENCHOUT_FILE})
                    file(RENAME ${BENCHOUT_FILE} "${BENCHOUT_FILE}.last")
                endif()
                add_test(${BENCHMARK_NAME} ${BENCHMARK_NAME} 
                    "--benchmark_format=console"
                    "--benchmark_out=${BENCHOUT_FILE}"
                    "--benchmark_out_format=json"
                )
            endif()
        endif()
    endif()
endfunction()

#
# #############################################################################
#
