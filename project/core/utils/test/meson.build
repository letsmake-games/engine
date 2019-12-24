#
# (c) LetsMakeGames 2019
# http://www.letsmake.games
#

utils_test = executable(
  'utils_test',
  [
    'Exception.cc',
    'glm.cc',
    'String.cc'
  ],
  dependencies: [
    FMT_DEP,
    GLM_DEP,
    GTEST_DEP,
    GTEST_MAIN_DEP,
    UTILS_DEP
  ]
)

test('UTILS tests', utils_test)
