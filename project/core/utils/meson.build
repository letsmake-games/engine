#
# (c) LetsMakeGames 2019
# http://www.letsmake.games
#

UTILS = static_library(
  'UTILS', 
  [
    'String.cc'
  ],
  dependencies: [
    FMT_DEP,
    GLM_DEP
  ],
  pic: true,
  include_directories: [
    ENGINE_INCLUDES,
  ]
)

UTILS_DEP = declare_dependency(
  link_with: UTILS,
  dependencies: [
    FMT_DEP,
    GLM_DEP
  ],
  include_directories: [
    ENGINE_INCLUDES
  ]
)

subdir('benchmark')
subdir('test')
