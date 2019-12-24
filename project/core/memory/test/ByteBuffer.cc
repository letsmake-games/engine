//
// (C) LetsMakeGames 2019
// http://www.letsmake.games
//

#include "core/memory/ByteBuffer.hh"

#include <gtest/gtest.h>

//
// ----------------------------------------------------------------------------
//

TEST(Test_ByteBuffer, Construction)
{
    blacktriangles::ByteBuffer {};
}

//
// ----------------------------------------------------------------------------
//

TEST(Test_FixedByteBuffer, Construction)
{
    blacktriangles::FixedByteBuffer<128> buff;
    EXPECT_EQ(buff.size(), 128);
}

//
// ----------------------------------------------------------------------------
//

TEST(Test_ByteBuffer, ArrayView)
{
}
