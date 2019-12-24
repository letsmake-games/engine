#
# (c) LetsMakeGames 2019
# http://www.letsmake.games
#

#
# Configure shared header #####################################################
#

configure_file(
  input: 'Engine.hh.in',
  output: 'Engine.hh',
  configuration: {
    'PROJECT_NAME': PROJECT_NAME,
    'PROJECT_MAJOR': PROJECT_MAJOR,
    'PROJECT_MINOR': PROJECT_MINOR,
    'PROJECT_PATCH': PROJECT_PATCH,
    'PROJECT_VERSION': PROJECT_VERSION
  }
)

#
# Sub Directories #############################################################
#

subdir('core')
subdir('glfw')
subdir('window')
