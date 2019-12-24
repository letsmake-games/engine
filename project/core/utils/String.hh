//
// (C) LetsMakeGames 2019
// http://www.letsmake.games
//

#pragma once

#include "Engine.hh"

#include <string>
#include <vector>

namespace Engine
{

//
// splits a string into a vector of strings given a delimeter
// 
std::vector<std::string> split(const std::string& s, const std::string& delim);

} // blacktriangles
