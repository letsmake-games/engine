//
// (C) LetsMakeGames 2019
// http://www.letsmake.games
//

#include "core/utils/String.hh"

#include <benchmark/benchmark.h>
#include <fmt/format.h>

//
// Split single delimeter /////////////////////////////////////////////////////
//

static void String_Split(benchmark::State& state)
{
    for( auto _ : state )
    {
        std::vector<std::string> s = blacktriangles::split("192.168.1.1", ".");
    }
}
BENCHMARK(String_Split);

//
// Format string using fmt library ////////////////////////////////////////////
//


static void String_Format(benchmark::State& state)
{
    for(auto _ : state)
    {
        std::string s = fmt::format("Format {0} with {1}", "foo", 100);
    }
}
BENCHMARK(String_Format);
