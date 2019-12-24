#
# (c) LetsMakeGames 2019
# http://www.letsmake.games
#

GLFW_WINDOW = static_library(
  'glfw_window',
  [
    'WindowManager.cc'
  ],
  dependencies: [
    GLAD_DEP,
    GLFW_DEP,
    ID_DEP
  ],
  include_directories: [
    ENGINE_INCLUDES
  ]
)

GLFW_WINDOW_DEP = declare_dependency(
  link_with: [
    GLFW_WINDOW
  ],
  dependencies: [
    GLAD_DEP,
    GLFW_DEP,
    ID_DEP
  ],
  include_directories: [
    ENGINE_INCLUDES
  ]
)
