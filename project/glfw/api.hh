//
// (c) LetsMakeGames 2019
// http://www.letsmake.games
//

#pragma once

#include "Engine.hh"

namespace Engine::glfw
{

//
// startup ////////////////////////////////////////////////////////////////////
// Must be called before any glfw modules can be used.

bool startup();

//
// shutdown ///////////////////////////////////////////////////////////////////
// Must be called after glfw is finished being used.

void shutdown();

} // engine::glfw
