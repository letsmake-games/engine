#
# (c) LetsMakeGames 2019
# http://www.letsmake.games
#

cmake = import('cmake')

#
# FMT #########################################################################
#

FMT = cmake.subproject('fmt', cmake_options: [
  '-DMASTER_PROJECT=OFF',
  '-DFMT_DOC=OFF',
  '-DFMT_INSTALL=OFF',
  '-DFMT_TEST=OFF'
])
FMT_DEP = FMT.dependency('fmt')

#
# GLAD ########################################################################
#

GLAD = subproject('glad')
GLAD_DEP = GLAD.get_variable('glad_dep')

#
# GLFW ########################################################################
#

GLFW = cmake.subproject('glfw', cmake_options: [
  '-DGLFW_BUILD_EXAMPLES=OFF',
  '-DGLFW_BUILD_TESTS=OFF',
  '-DGLFW_BUILD_DOCS=OFF',
  '-DGLFW_INSTALL=OFF'
])
GLFW_DEP = GLFW.dependency('glfw')

#
# GLM #########################################################################
#

GLM = cmake.subproject('glm', cmake_options: [
  '-DGLM_TEST_ENABLE=OFF'
])
glm_includes = include_directories('../subprojects/glm')
GLM_DEP = declare_dependency(
  include_directories: glm_includes
)

#
# Gtest #######################################################################
#
GTEST = subproject('gtest')
GTEST_DEP = GTEST.get_variable('gtest_dep')
GTEST_MAIN_DEP = GTEST.get_variable('gtest_main_dep')

#
# Google Benchmark ############################################################
#

GBENCH = subproject('google-benchmark')
GBENCH_DEP = GBENCH.get_variable('google_benchmark_dep')
GBENCH_MAIN_DEP = GBENCH.get_variable('google_benchmark_main_dep')
