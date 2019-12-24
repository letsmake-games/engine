//
// (C) LetsMakeGames 2019
// http://www.letsmake.games
//

#pragma once

#include "Engine.hh"

#include <array>
#include <cstddef>
#include <vector>

namespace Engine
{

using byte = uint8_t;

//
// Memory Buffer
//
using ByteBuffer = std::vector<byte>;

//
// Fixed size memory buffer
//
template<size_t length>
using FixedByteBuffer = std::array<byte, length>;

} // blacktriangles
