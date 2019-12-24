//
// (C) LetsMakeGames 2019
// http://www.letsmake.games/
//

#include "core/id/HashIdClass.hh"

#include <gtest/gtest.h>
#include <sstream>

//
// Test Types /////////////////////////////////////////////////////////////////
//

DECLARE_HASHIDCLASS(HashId);

//
// Equality ///////////////////////////////////////////////////////////////////
//

TEST(Test_HashIdClass, Construction)
{
    //
    // default constructed hashes are invalid
    //
    HashId id1;
    EXPECT_EQ(id1, HashId::InvalidHash);
    EXPECT_EQ(id1.hash(), HashId::InvalidHashValue);

    //
    // you can construct a hash with a precomputed hash value
    //
    HashId id2(10);
    EXPECT_NE(id1, id2);
    EXPECT_NE(id2, HashId::InvalidHash);
    EXPECT_NE(id1.hash(), id2.hash());
    EXPECT_EQ(id2.hash(), 10);

    //
    // you can construct a hash id from a string
    //
    HashId id3("string");
    EXPECT_NE(id2, id3);
    EXPECT_NE(id3, HashId::InvalidHash);

    //
    // equivalent strings produce equivalent hashes
    //
    HashId id4("string");
    EXPECT_EQ(id3, id4);

    //
    // wstrings != strings
    //
    HashId id5(L"string");
    EXPECT_NE(id4, id5);

    //
    // different strings produce different hashes
    //
    HashId id6("other string");
    EXPECT_NE(id3, id6);

    //
    // you can copy construct
    //
    HashId id7(id6);
    EXPECT_EQ(id7, id6);

    //
    // you can move construct
    //
    HashId id8(std::move(id4));
    EXPECT_EQ(id3, id8);
}

//
// Operators //////////////////////////////////////////////////////////////////
//

TEST(Test_HashIdClass, Operators)
{
    //
    // stream support
    //
    HashId id1(10);
    std::stringstream ss;
    ss << id1;
    EXPECT_EQ(ss.str(), "10");

    //
    // lt
    //
    HashId id2(10);
    EXPECT_EQ(id1, id2);
    EXPECT_LE(id1, id2);
    EXPECT_GE(id1, id2);
    EXPECT_FALSE(id1 < id2);
    EXPECT_FALSE(id1 > id2);

    //
    //
    //
    HashId id3;
    EXPECT_NE(id1, id3);
    EXPECT_LE(id3, id1);
    EXPECT_GE(id1, id3);
}

//
// ############################################################################
//
