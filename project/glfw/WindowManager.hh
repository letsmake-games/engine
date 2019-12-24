//
// (C) LetsMakeGames 2019
// http://www.letsmake.games
//

#pragma once

#include "Engine.hh"

#include "window/WindowManager.hh"

#include <array>
#include "glad/gl.h"
#include "GLFW/glfw3.h"
#include <string>
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

    //
    // opens a new window, returning a window id to refer it it later
    //
    virtual WindowId open(const WindowSettings& settings) override;

    //
    //
    //
    virtual void configure(WindowId id, const WindowSettings& settings) override;

    //
    // closes a window that was previously opened
    //
    virtual void close(WindowId window) override;

private: // private methods ///////////////////////////////////////////////////

    //
    //
    //
    GLFWwindow* getWindow(WindowId id) const;

    //
    //
    //
    WindowId::IdType getNextAvailableWindowIdx() const;

    //
    //
    //
    void configure(GLFWwindow* window, const WindowSettings& settings);

private: // members ///////////////////////////////////////////////////////////

    std::array<GLFWwindow*, WindowId::InvalidValue> m_windows;

};

} // Engine::glfw
