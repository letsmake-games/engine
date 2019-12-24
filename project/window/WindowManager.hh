//
// (C) LetsMakeGames 2019
// http://www.letsmake.games
//

#pragma once

#include "Engine.hh"
#include "core/id/IdClass.hh"

namespace Engine
{

//
// Id Generator ///////////////////////////////////////////////////////////////
//

DECLARE_IDCLASS(WindowId, uint8_t);
DECLARE_SEQUENTIAL_IDGENERATOR(WindowId);

//
// Window Manager /////////////////////////////////////////////////////////////
//
class WindowManager
{
public: // public methods /////////////////////////////////////////////////////

    virtual WindowId open(size_t width, size_t height) = 0;

    virtual void close(WindowId window) = 0;
};

} // blacktriangles
