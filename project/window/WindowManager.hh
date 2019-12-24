//
// (C) LetsMakeGames 2019
// http://www.letsmake.games
//

#pragma once

#include "Engine.hh"
#include "core/id/IdClass.hh"

#include "glm/glm.hpp"
#include <string>

namespace Engine
{

//
// WindowId ///////////////////////////////////////////////////////////////////
//

DECLARE_IDCLASS(WindowId, uint8_t);

//
// Window Mode ////////////////////////////////////////////////////////////////
//

enum WindowMode
{
    Windowed = 0,   // a normal window
    Fullscreen,     // a fullscreen window
    Borderless      // a normal window which occupies the entire screen
};

//
// Window Manager /////////////////////////////////////////////////////////////
//

class WindowManager
{

public: // types //////////////////////////////////////////////////////////////

    //
    //
    //
    struct WindowSettings
    {
        glm::uvec2 screenPos  = glm::uvec2(0,0);
        glm::uvec2 screenSize = glm::uvec2(800,600);
        std::string title     = "";
        WindowMode mode       = WindowMode::Fullscreen;
    };

public: // public methods /////////////////////////////////////////////////////

    //
    //
    //
    virtual WindowId open(const WindowSettings& settings) = 0;

    //
    //
    //
    virtual void configure(WindowId id, const WindowSettings& settings) = 0;

    //
    //
    //
    virtual void close(WindowId window) = 0;

};

}


