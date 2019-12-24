#
# (c) LetsMakeGames 2019
# http://www.letsmake.games
#

#
# API Library #################################################################
#

bt_add_library(
    glfw_api STATIC
    SOURCES
        api.cc

    LIBRARIES 
        engine
        glfw
)

#
# Window Library ##############################################################
#

bt_add_library(
    glfw_window STATIC
    SOURCES
        WindowManager.cc

    LIBRARIES
        engine
        glad
        glfw_api
        glm
        window
)
