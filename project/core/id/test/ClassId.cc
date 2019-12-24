//
// (C) LetsMakeGames 2019
// http://www.letsmake.games
//

#include "core/id/ClassId.hh"

#include <gtest/gtest.h>

//
// test types /////////////////////////////////////////////////////////////////
//

class ClassA
{
    DECLARE_CLASSID_NOBASE(ClassA);
    virtual ~ClassA() = default;
};

//
// ----------------------------------------------------------------------------
//

class ClassB
    : public ClassA
{
    DECLARE_CLASSID(ClassB, ClassA);
};

//
// ----------------------------------------------------------------------------
//

class ClassC
    : public ClassB
{
    DECLARE_CLASSID(ClassC, ClassB);
};

//
// ----------------------------------------------------------------------------
//

class ClassD
    : public ClassA
{
    DECLARE_CLASSID(ClassD, ClassA);
};

//
// ----------------------------------------------------------------------------
//

class ClassE
{
    DECLARE_CLASSID_NOBASE(ClassE)
    virtual ~ClassE() = default;
};


//
// IsTypeOf ///////////////////////////////////////////////////////////////////
//

TEST(Test_ClassId, StaticIsTypeOf)
{
    EXPECT_TRUE (ClassA::isTypeOf<ClassA>());
    EXPECT_FALSE(ClassA::isTypeOf<ClassB>());
    EXPECT_TRUE (ClassB::isTypeOf<ClassA>());
    EXPECT_TRUE (ClassC::isTypeOf<ClassA>());
    EXPECT_TRUE (ClassC::isTypeOf<ClassB>());
    EXPECT_TRUE (ClassD::isTypeOf<ClassA>());
    EXPECT_FALSE(ClassD::isTypeOf<ClassB>());
    EXPECT_FALSE(ClassE::isTypeOf<ClassA>());
}

//
// Comparison /////////////////////////////////////////////////////////////////
//

TEST(Test_ClassId, Comparison)
{
    EXPECT_NE(ClassA::getStaticClassId(), ClassB::getStaticClassId());
    EXPECT_EQ(ClassA::getStaticClassId(), ClassA::getStaticClassId());
    EXPECT_EQ(&ClassA::getStaticClassId(), ClassB::getStaticClassId().getBaseClassId());
    EXPECT_NE(&ClassA::getStaticClassId(), ClassC::getStaticClassId().getBaseClassId());
    EXPECT_NE(&ClassA::getStaticClassId(), &ClassE::getStaticClassId());
    EXPECT_EQ(ClassA::getStaticClassId().getBaseClassId(), nullptr);
    EXPECT_NE(ClassB::getStaticClassId().getBaseClassId(), nullptr);

    EXPECT_EQ(ClassA::getStaticClassId().getName(), "ClassA");
    EXPECT_EQ(ClassB::getStaticClassId().getName(), "ClassB");
}

//
// Casting ////////////////////////////////////////////////////////////////////////////
//

TEST(Test_ClassId, Casting)
{
    ClassC::Ptr ptrc = ClassC::Ptr(new ClassC());
    ClassE::Ptr ptre = ClassE::Ptr(new ClassE());

    ClassA::Ptr a = ClassC::ptrCast(ptrc);
    //does not compile ClassA::Ptr a2 = ClassE::ptrCast(ptre);
    EXPECT_EQ(a.get(), ptrc.get());
}

//
// ############################################################################
//
