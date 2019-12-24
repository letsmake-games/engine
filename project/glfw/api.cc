//
// (c) LetsMakeGames 2019
// http://www.letsmake.games
//

#include "glfw/api.hh"

#include "GLFW/glfw3.h"

namespace Engine::glfw
{

//
// ----------------------------------------------------------------------------
//

bool startup()
{
    static bool started = false;
    if(!started)
    {
        started = glfwInit();
        if(!started)
        {
            Engine::glfw::shutdown();
        }
    }

    return started;
}

//
// ----------------------------------------------------------------------------
//

void shutdown()
{
    glfwTerminate();
}

}
