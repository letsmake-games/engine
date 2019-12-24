//
// (c) LetsMakeGames 2019
// http://www.letsmake.games
//

#include "core/id/IdClass.hh"
#include "core/id/SequentialIdGenerator.hh"

#include "gtest/gtest.h"

//
// types //////////////////////////////////////////////////////////////////////
//

DECLARE_IDCLASS(BasicId, uint8_t);

//
// Generator //////////////////////////////////////////////////////////////////
//

TEST(Test_SequentialIdGenerator, Generation )
{
    //
    // generate an id
    //
    Engine::SequentialIdGenerator<BasicId> generator;

    BasicId id1 = generator.next();
    EXPECT_NE(id1, BasicId::InvalidId);
    EXPECT_EQ(id1.getRawId(), 0);

    //
    // the last id should be the id we just generated
    //
    BasicId id1_2 = generator.prev();
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
    // prev always returns the last VALID id
    //
    EXPECT_EQ(BasicId(BasicId::InvalidValue-1), generator.prev());

    //
    // we can reset a generator to recycle old ids
    //
    generator.reset();
    BasicId id1_3 = generator.next();
    EXPECT_EQ(id1, id1_3);
}
