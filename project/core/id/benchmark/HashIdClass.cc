//
// (C) LetsMakeGames 2019
// http://www.letsmake.games
//

#include "core/id/HashIdClass.hh"

#include <benchmark/benchmark.h>

DECLARE_HASHIDCLASS(TestHashId);

static void HashId_HashConstructor(benchmark::State& state)
{
    for(auto _ : state)
    {
       TestHashId("some roadtrip");
    }
}
BENCHMARK(HashId_HashConstructor);
