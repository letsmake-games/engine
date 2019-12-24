#
# (c) LetsMakeGames 2019
# http://www.letsmake.games
#

bt_add_executable(
    editor
    SOURCES
        editor.cc
    
    LIBRARIES
        engine
        glfw_api
        glfw_window
)
