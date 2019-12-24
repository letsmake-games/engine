//
// (C) LetsMakeGames 2019
// http://www.letsmake.games
//

#pragma once

#include "Engine.hh"
#include "window/WindowManager.hh"

#include "glad/gl.h"
#include <GLFW/glfw3.h>
#include <vector>

namespace Engine::glfw
{

//
// A GLFW based window
//
class WindowManager final
    : public Engine::WindowManager
{
public: // constructor / destructor ///////////////////////////////////////////

    //
    // default constructor
    //
    WindowManager();

    //
    // deconstructor
    //
    ~WindowManager();

public: // public methods /////////////////////////////////////////////////////

    inline bool isInitialized() const                           { return m_initialized; }

    virtual WindowId open(size_t width, size_t height) override;

    virtual void close(WindowId window) override;

private: // members ///////////////////////////////////////////////////////////

    bool m_initialized;

    std::vector<GLFWwindow*> m_windows;
};

} // Engine::glfw
