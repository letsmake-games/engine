//
// (C) LetsMakeGames 2019
// http://www.letsmake.games/
//

#include "core/id/IdClass.hh"

#include "gtest/gtest.h"

//
// Test Types /////////////////////////////////////////////////////////////////
//

DECLARE_IDCLASS(BasicId, uint8_t);

//
// Construction ///////////////////////////////////////////////////////////////
//

TEST(Test_IdClass, Construction)
{
    BasicId id1;
    EXPECT_EQ(id1, BasicId::InvalidId);
    EXPECT_EQ(id1.getRawId(), BasicId::InvalidValue);

    BasicId id2(1);
    EXPECT_NE(id1, id2);
    EXPECT_NE(id2, BasicId::InvalidId);
    EXPECT_EQ(id2.getRawId(), 1);

    BasicId id3(id2);
    EXPECT_EQ(id3, id2);

    BasicId id4(std::move(id3));
    EXPECT_EQ(id4, id2);
}

//
// Equality ///////////////////////////////////////////////////////////////////
//

TEST(Test_IdClass, Equality)
{
    BasicId id1;
    BasicId id2;

    EXPECT_EQ(BasicId::max, std::numeric_limits<uint8_t>::max());

    EXPECT_EQ(id1, id2);
    EXPECT_EQ(id1, BasicId::InvalidId);
    EXPECT_EQ(id1.getRawId(), BasicId::max);

    BasicId id3(1);
    EXPECT_NE(id1, id3);
    EXPECT_NE(id3, BasicId::InvalidId);
    EXPECT_NE(id3.getRawId(), BasicId::max);
}

//
// ############################################################################
//
