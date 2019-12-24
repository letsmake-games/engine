#
# (c) LetsMakeGames 2019
# http://www.letsmake.games
#

bt_add_library(
    memory INTERFACE
    INTERFACE_LIBRARIES
        engine
)

#
# tests #######################################################################
#

bt_add_test(
    memory

    BENCHMARKS
        benchmark/ByteBuffer.cc
    TESTS
        test/ByteBuffer.cc

    LIBRARIES
        memory
)

