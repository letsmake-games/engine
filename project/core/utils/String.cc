//
// (C) LetsMakeGames 2019
// http://www.letsmake.games
//

#include "core/utils/String.hh"

#include <cstdio>
#include <stdarg.h>

namespace blacktriangles
{

//
// -------------------------------------------------------------------------
//

std::vector<std::string> split(const std::string& s, const std::string& delim)
{
    std::vector<std::string> result;
    size_t last_pos = 0;
    size_t pos = 0;
    while((pos = s.find(delim, last_pos)) != std::string::npos)
    {
        result.push_back(s.substr(last_pos,pos-last_pos));
        last_pos = pos + delim.length();
    }
    
    std::string rem = s.substr(last_pos);  
    if(!rem.empty())
    {
        result.emplace_back(std::move(rem));
    }

    return result;
}

} // blacktriangles
