#
# (C) LetsMakeGames 2019
# http://www.letsmake.games
#

bt_add_library(
    utils STATIC
    SOURCES
        String.cc
    LIBRARIES
        engine
        memory
)

#
# tests #######################################################################
#

bt_add_test(
    utils
    TESTS 
        test/Exception.cc
        test/glm.cc
        test/String.cc

    BENCHMARKS
        benchmark/String.cc

    LIBRARIES
        utils
        fmt
        glm
)
