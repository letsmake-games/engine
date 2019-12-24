#
# (C) LetsMakeGames 2019
# http://www.letsmake.games
#

#
# configure file
#

configure_file(Engine.hh.in ${CMAKE_CURRENT_BINARY_DIR}/Engine.hh)

#
# subdirectories
#

add_subdirectory(core)
add_subdirectory(glfw)
add_subdirectory(window)

#
# main library
#

bt_add_library( 
    engine INTERFACE
    INTERFACE_LIBRARIES

    INTERFACE_INCLUDES
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_BINARY_DIR}
)
