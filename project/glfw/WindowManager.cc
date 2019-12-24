//
// (C) LetsMakeGames 2019
// http://www.letsmake.games
//

#include "glfw/WindowManager.hh"

namespace Engine::glfw
{

//
// constructor /destructor ////////////////////////////////////////////////////
//

WindowManager::WindowManager()
    : m_initialized(false)
    , m_windows()
{
    if(!glfwInit())
    {
        glfwTerminate();
    }
    else
    {
        m_initialized = true;
    }
}

//
// ----------------------------------------------------------------------------
//

WindowManager::~WindowManager()
{
    glfwTerminate();
    m_initialized = false;
}

//
// public methods /////////////////////////////////////////////////////////////
//

WindowId WindowManager::open(size_t width, size_t height)
{
    return WindowId(0);
}

//
// ----------------------------------------------------------------------------
//

void WindowManager::close(WindowId id)
{
}

} // Engine::glfw
