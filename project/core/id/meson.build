#
# (c) LetsMakeGames 2019
# http://www.letsmake.games
#

ID = library(
  'id', 
  [
    'ClassId.cc'
  ],
  include_directories: [
    ENGINE_INCLUDES
  ]
)

ID_DEP = declare_dependency(
  link_with: [ID],
  include_directories: [
    ENGINE_INCLUDES
  ]
)

subdir('benchmark')
subdir('test')
