//
// (C) LetsMakeGames 2019
// http://www.letsmake.games
//

#include "glfw/api.hh"
#include "glfw/WindowManager.hh"

#include <assert.h>

namespace Engine::glfw
{

//
// constructor /destructor ////////////////////////////////////////////////////
//

WindowManager::WindowManager()
{
    Engine::glfw::startup();
    m_windows.fill(nullptr);
}

//
// ----------------------------------------------------------------------------
//

WindowManager::~WindowManager()
{
}

//
// public methods /////////////////////////////////////////////////////////////
//

WindowId WindowManager::open(const WindowSettings& settings)
{
    // check to see if we have any open slots for a new window, if not return
    // an invalid id
    WindowId::IdType idx = getNextAvailableWindowIdx();
    if(idx == WindowId::InvalidValue)
    {
        return WindowId::InvalidId;
    }

    GLFWwindow* window = glfwCreateWindow(settings.screenSize.x, settings.screenSize.y, "", nullptr, nullptr);
    configure(window, settings);

    m_windows[idx] = window;
    return WindowId(idx);
}

//
// ----------------------------------------------------------------------------
//

void WindowManager::configure(WindowId id, const WindowSettings& settings)
{
    GLFWwindow* window = getWindow(id);
    if(window != nullptr)
    {
        configure(window, settings);
    }
}

//
// ----------------------------------------------------------------------------
//

void WindowManager::close(WindowId id)
{
    if(id != WindowId::InvalidId)
    {
        const WindowId::IdType idx = id.getRawId();
        assert(idx >= 0 && idx < WindowId::max);
        GLFWwindow* window = m_windows[idx];
        if(window != nullptr)
        {
            glfwDestroyWindow(window);
        }
        m_windows[idx] = nullptr;
    }
}

//
// private methods ////////////////////////////////////////////////////////////
//

GLFWwindow* WindowManager::getWindow(WindowId id) const
{
    GLFWwindow* result = nullptr;
    if(id != WindowId::InvalidId)
    {
        const WindowId::IdType idx = id.getRawId();
        
        result = m_windows[idx];
    }

    return result;
}

//
// ----------------------------------------------------------------------------
//


WindowId::IdType WindowManager::getNextAvailableWindowIdx() const
{
    for(WindowId::IdType idx = 0; idx < WindowId::max; ++idx)
    {
        if(m_windows[idx] == nullptr)
        {
            return idx;
        }
    }

    return WindowId::InvalidValue;
}

//
// ----------------------------------------------------------------------------
//

void WindowManager::configure(GLFWwindow* window, const WindowSettings& settings)
{
    if(window == nullptr)
    {
        return;
    }

    GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* videoMode = glfwGetVideoMode(primaryMonitor);

    int width = settings.screenSize.x;
    int height = settings.screenSize.y;
    int refreshRate = videoMode->refreshRate;
    glfwWindowHint(GLFW_RED_BITS, videoMode->redBits);
    glfwWindowHint(GLFW_GREEN_BITS, videoMode->greenBits);
    glfwWindowHint(GLFW_BLUE_BITS, videoMode->blueBits);
    glfwWindowHint(GLFW_REFRESH_RATE, videoMode->refreshRate);

    GLFWmonitor* monitor = nullptr;
    switch(settings.mode)
    {
        case WindowMode::Fullscreen:
        {
            monitor = primaryMonitor;
        }
        break;

        case WindowMode::Borderless:
        {
            width = videoMode->width;
            height = videoMode->height;
            glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);
        }
        break;

        default:
        case WindowMode::Windowed:
        break;
    }

    glfwSetWindowMonitor(window, monitor, settings.screenPos.x, settings.screenPos.y, width, height, refreshRate);
    glfwSetWindowTitle(window, settings.title.c_str());
}

} // Engine::glfw
