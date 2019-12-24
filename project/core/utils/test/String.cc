//
// (C) LetsMakeGames 2019
// http://www.letsmake.games
//

#include "core/utils/String.hh"

#include <gtest/gtest.h>

//
// ----------------------------------------------------------------------------
//

TEST(Test_String, Split)
{
    std::vector<std::string> result = Engine::split("test", ":");
    EXPECT_EQ(result.size(), 1);
    EXPECT_EQ(result[0], "test");

    result = Engine::split("abc.123", ".");
    EXPECT_EQ(result.size(), 2);
    EXPECT_EQ(result[0], "abc");
    EXPECT_EQ(result[1], "123");

    result = Engine::split("abc::123::", "::");
    EXPECT_EQ(result.size(), 2);
    EXPECT_EQ(result[0], "abc");
    EXPECT_EQ(result[1], "123");

    result = Engine::split("abc::::123", "::");
    EXPECT_EQ(result.size(), 3);
    EXPECT_EQ(result[0], "abc");
    EXPECT_EQ(result[1].empty(), true);
    EXPECT_EQ(result[2], "123");
}
