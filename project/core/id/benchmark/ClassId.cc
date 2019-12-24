//
// (C) LetsMakeGames 2019
// http://www.letsmake.games
//

#include "core/id/ClassId.hh"

#include <benchmark/benchmark.h>

//
// test classes ///////////////////////////////////////////////////////////////
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
    : public ClassC
{
    DECLARE_CLASSID(ClassD, ClassC);
};

//
// ----------------------------------------------------------------------------
//

class ClassE
    : public ClassD
{
    DECLARE_CLASSID(ClassE, ClassD);
    virtual ~ClassE() = default;
};

//
// ////////////////////////////////////////////////////////////////////////////
//

static void ClassId_isTypeOfFalse(benchmark::State& state)
{
    for(auto _ : state)
    {
        ClassA::isTypeOf<ClassB>();
    }
}
BENCHMARK(ClassId_isTypeOfFalse);

//
// -------------------------------------------------------------------------
//

static void ClassId_isTypeOfTrue(benchmark::State& state)
{
    for(auto _ : state)
    {
       ClassB::isTypeOf<ClassA>();
    }
}
BENCHMARK(ClassId_isTypeOfTrue);

//
// -------------------------------------------------------------------------
//

static void ClassId_isTypeOfDeep(benchmark::State& state)
{
    for(auto _ : state)
    {
        ClassC::isTypeOf<ClassA>();
    }
}
BENCHMARK(ClassId_isTypeOfDeep);

//
// -------------------------------------------------------------------------
//

static void ClassId_isTypeOfDeep2(benchmark::State& state)
{
    for(auto _ : state)
    {
        ClassD::isTypeOf<ClassA>();
    }
}
BENCHMARK(ClassId_isTypeOfDeep2);

//
// -------------------------------------------------------------------------
//

static void ClassId_isTypeOfDeep3(benchmark::State& state)
{
    for(auto _ : state)
    {
        ClassE::isTypeOf<ClassA>();
    }
}
BENCHMARK(ClassId_isTypeOfDeep3);

//
// -------------------------------------------------------------------------
//

static void ClassId_UnsafePtrCast(benchmark::State& state)
{
    ClassC::Ptr ptr = ClassC::Ptr(new ClassC); 
    for(auto _ : state)
    {
        ClassA::Ptr aptr = blacktriangles::ptrCast<ClassA>(ptr);
    }
}
BENCHMARK(ClassId_UnsafePtrCast);

//
// -------------------------------------------------------------------------
//

static void ClassId_PtrCast(benchmark::State& state)
{
    ClassC::Ptr ptr = ClassC::Ptr(new ClassC); 
    for(auto _ : state)
    {
        ClassA::Ptr aptr = ClassA::ptrCast(ptr);
    }
}
BENCHMARK(ClassId_PtrCast);


//
// -------------------------------------------------------------------------
//

static void ClassId_UnsafeHndCast(benchmark::State& state)
{
    ClassC::Ptr ptr = ClassC::Ptr(new ClassC); 
    ClassC::Handle weak = ptr;
    for(auto _ : state)
    {
        ClassA::Handle aptr = blacktriangles::handleCast<ClassA>(weak);
    }
}
BENCHMARK(ClassId_UnsafeHndCast);

//
// -------------------------------------------------------------------------
//

static void ClassId_HndCast(benchmark::State& state)
{
    ClassC::Ptr ptr = ClassC::Ptr(new ClassC); 
    ClassC::Handle weak = ptr;
    for(auto _ : state)
    {
        ClassA::Handle aptr = ClassA::handleCast(weak);
    }
}
BENCHMARK(ClassId_HndCast);
