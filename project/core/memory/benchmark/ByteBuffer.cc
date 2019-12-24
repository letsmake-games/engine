//
// (C) LetsMakeGames 2019
// http://www.letsmake.games
//

#include "core/memory/ByteBuffer.hh"

#include <benchmark/benchmark.h>

static void ByteBuffer_Creation(benchmark::State& state)
{
    blacktriangles::ByteBuffer* buff = nullptr;
    for(auto _ : state)
    {
        buff = new blacktriangles::ByteBuffer(128);
    }
    buff->clear();
    delete buff;
}
BENCHMARK(ByteBuffer_Creation);
