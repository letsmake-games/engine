#
# (c) LetsMakeGames 2019
# http://www.letsmake.games
#

bt_add_library(
    glfw_window STATIC
    SOURCES
        WindowManager.cc

    LIBRARIES
        glad
        glfw
        window
)
