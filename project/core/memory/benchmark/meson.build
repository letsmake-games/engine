#
# (c) LetsMakeGames 2019
# http://www.letsmake.games
#

memory_bench = executable(
  'memory_bench',
  [
    'ByteBuffer.cc'
  ],
  dependencies: [
    GBENCH_DEP,
    GBENCH_MAIN_DEP,
    MEMORY_DEP
  ]
)

benchmark('MEMORY benchmarks', memory_bench)
