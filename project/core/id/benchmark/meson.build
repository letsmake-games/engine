#
# (c) LetsMakeGames 2019
# http://www.letsmake.games
#

id_bench = executable(
  'id_bench',
  [
    'ClassId.cc',
    'HashIdClass.cc',
  ],
  dependencies: [
    ID_DEP,
    GBENCH_DEP,
    GBENCH_MAIN_DEP
  ],
)

benchmark('id benchmarks', id_bench)
