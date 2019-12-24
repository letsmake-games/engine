#
# (C) LetsMakeGames 2019
# http://www.letsmake.games
#

bt_add_library(
    id STATIC
    SOURCES
        ClassId.cc
    LIBRARIES
        engine
)

#
# #############################################################################
#

bt_add_test(
    id
    TESTS
        test/ClassId.cc
        test/HashIdClass.cc
        test/IdClass.cc
        test/SequentialIdGenerator.cc
    
    BENCHMARKS
        benchmark/ClassId.cc
        benchmark/HashIdClass.cc
    
    LIBRARIES
        id
)
