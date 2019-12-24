//
// (C) LetsMakeGames 2019
// http://www.letsmake.games
//

#include <gtest/gtest.h>

#include <glm/vec3.hpp>

//
// ----------------------------------------------------------------------------
//

TEST(Test_glm, Integration)
{
    glm::vec3 vec(0.0f, 1.0f, 2.0f);
    EXPECT_FLOAT_EQ(vec.x, 0.0f);
    EXPECT_FLOAT_EQ(vec.y, 1.0f);
    EXPECT_FLOAT_EQ(vec.z, 2.0f);
}
