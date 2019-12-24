//
// (C) LetsMakeGames 2019
// http://www.letsmake.games/
//

#include "core/id/IdClass.hh"

#include <gtest/gtest.h>

//
// Test Types /////////////////////////////////////////////////////////////////
//

DECLARE_IDCLASS(BasicId, uint8_t);
DECLARE_SEQUENTIAL_IDGENERATOR(BasicId);

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

    EXPECT_EQ(id1, id2);
    EXPECT_EQ(id1, BasicId::InvalidId);
    EXPECT_EQ(id1.getRawId(), std::numeric_limits<uint8_t>::max());

    BasicId id3(1);
    EXPECT_NE(id1, id3);
    EXPECT_NE(id3, BasicId::InvalidId);
    EXPECT_NE(id3.getRawId(), std::numeric_limits<uint8_t>::max());
}

//
// Generator //////////////////////////////////////////////////////////////////
//

TEST(Test_IdClass, Generator )
{
    //
    // generate an id
    //
    IdGenerator::BasicIdGenerator generator;
    BasicId id1 = generator.next();
    EXPECT_NE(id1, BasicId::InvalidId);
    EXPECT_EQ(id1.getRawId(), 0);

    //
    // the last id should be the id we just generated
    //
    BasicId id1_2 = generator.last();
    EXPECT_EQ(id1, id1_2);

    //
    // generate another id
    //
    BasicId id2 = generator.next();
    EXPECT_NE(id2, BasicId::InvalidId);
    EXPECT_NE(id1, id2);

    //
    // once we run out of numbers, we generate only InvalidIds
    //
    for(size_t i = 0; i != 256; ++i )
    {
        generator.next();
    }

    EXPECT_EQ(generator.next(), BasicId::InvalidId);
    EXPECT_EQ(generator.next(), BasicId::InvalidId);

    //
    // we can reset a generator to recycle old ids
    //
    BasicId id1_3 = generator.next(true);
    EXPECT_EQ(id1, id1_3);


    //
    // we can also use a static shared generator
    //
    BasicId id1_4 = IdGenerator::generateBasicId();
    EXPECT_EQ(id1, id1_4);

    BasicId id2_2 = IdGenerator::generateBasicId();
    EXPECT_EQ(id2, id2_2);
}

//
// ############################################################################
//
