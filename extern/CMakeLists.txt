#
# blacktriangles (c) 2019
# http://www.letsmake.games
#

#
# fmt #########################################################################
#

add_subdirectory("fmt")

#
# glm #########################################################################
#

option(GLM_TEST_ENABLE OFF)
add_subdirectory("glm")

#
# google benchmarks ###########################################################
#

option(BENCHMARK_ENABLE_TESTING "Enable Google Benchmark Testing" OFF)
option(BENCHMARK_ENABLE_INSTALL "Install Google Benchmark to the System" OFF)
add_subdirectory("gbench")

#
# glad ########################################################################
#

add_subdirectory(glad)

#
# glfw ########################################################################
#

option(GLFW_BUILD_EXAMPLES "Build the GLFW example programs" OFF)
option(GLFW_BUILD_TESTS "Build the GLFW test programs" OFF)
option(GLFW_BUILD_DOCS "Build the GLFW documentation" OFF)
option(GLFW_INSTALL "Generate installation target" OFF)
add_subdirectory(glfw)

#
# google test #################################################################
#

add_subdirectory("gtest")

mark_as_advanced(
    BUILD_GMOCK BUILD_GTEST BUILD_SHARED_LIBS
    gmock_build_tests gtest_build_samples gtest_build_tests
    gtest_disable_pthreads gtest_force_shared_crt gtest_hide_internal_symbols
)

#
# #############################################################################
#

