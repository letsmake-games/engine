//
// (C) LetsMakeGames 2019
// http://www.letsmake.games
//

#include "core/utils/Exception.hh"

#include <gtest/gtest.h>

#include <iostream>

//
// ----------------------------------------------------------------------------
//

TEST(Test_Exception, What)
{
    Engine::Exception ex;
    EXPECT_STREQ(ex.what(), "");

    ex << "This";
    EXPECT_STREQ(ex.what(), "This");

    ex << " is a test";
    EXPECT_STREQ(ex.what(), "This is a test");
}

