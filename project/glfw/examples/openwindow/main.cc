//
// (c) LetsMakeGames 2019
// http://www.letsmake.games
//

#include "glfw/api.hh"
#include "glfw/WindowManager.hh"

#include <thread>
#include <chrono>

//
// main entry point ///////////////////////////////////////////////////////////
//

using namespace std::chrono_literals;

int main(int argc, char** argv)
{
    Engine::glfw::startup();
    Engine::glfw::WindowManager winman;

    Engine::WindowManager::WindowSettings settings {
        glm::uvec2(100,100),            // pos
        glm::uvec2(800,600),            // size
        "Editor",                       // title
        Engine::WindowMode::Windowed    // mode
    };

    Engine::WindowId window = winman.open(settings);

    std::this_thread::sleep_for(5s);

    winman.close(window);
    Engine::glfw::shutdown();

    return 0;
}
