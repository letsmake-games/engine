#
# (c) LetsMakeGames 2019
# http://www.letsmake.games
#

utils_bench = executable(
  'utils_bench',
  [
    'String.cc'
  ],
  dependencies: [
    UTILS_DEP,
    GBENCH_DEP,
    GBENCH_MAIN_DEP
  ],
  include_directories: [
    ENGINE_INCLUDES
  ]
)

benchmark('UTILS benchmarks', utils_bench)
