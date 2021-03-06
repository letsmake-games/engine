#!/bin/bash

#
# Useful variables ############################################################
#

BEGIN=$(tput bold)$(tput setaf 3)
END=$(tput sgr0)
FINAL=$(tput bold)$(tput setaf 2)
ALERT=$(tput bold)$(tput setaf 4)$(tput setb 7)

#
# Arguments ###################################################################
#

NOPROMPT=false
if [[ $1 =~ '-y' ]]
then
    NOPROMPT=true
fi

#
# VERSIONS ####################################################################
#

NVM_VER=v0.35.2
CMAKE_VER=3.16.0

#
# update submodules ###########################################################
#

echo "${BEGIN}Updating submodules...${END}"
git submodule update --init --recursive

#
# Update system libraries #####################################################
#

if [[ $NOPROMPT = false ]]
then
    read -p "${BEGIN}It is highly recommended you update system dependencies now.  We \
will also install some additional system dependencies, such as Ninja build system \
and build-essential.  Would you like us to do that for you? [y/n] ${END}"
fi

if [[ $REPLY =~ ^[Yy]$ ]] || [[ $NOPROMPT = true ]]
then
  echo "${BEGIN}Updating...${END}"
  sudo apt-get update

  echo "${BEGIN}Installing system dependencies...${END}"
  sudo apt-get install curl ninja-build build-essential libgl1-mesa-dev xorg-dev -y
 
  sudo apt-get upgrade -y
  echo "${BEGIN}Upgrading...${END}"

fi

#
# Install CMake ###############################################################
#

clear
if [[ $NOPROMPT = false ]]
then
    read -p "${BEGIN}This project uses CMake to build it's native libraries.  If you have a \
globally accessible cmake binary, you can skip this step, or install it yourself. \
Would you like us to install cmake now? [y/n] ${END}"
fi

if [[ $REPLY =~ ^[Yy]$ ]] || [[ $NOPROMPT = true ]] 
then

  if [[ $NOPROMPT = false ]]
  then
    read -p "${BEGIN}Where would you like to install it?${END} (default: $HOME/.bin)"
    echo ""
  fi

  if [[ -z "$REPLY" ]] || [[ $NOPROMPT = true ]]
  then
    CMAKE_INSTALL_DIR=$HOME/.bin
  else
    CMAKE_INSTALL_DIR=$REPLY
  fi

  mkdir -p $CMAKE_INSTALL_DIR

  # cache the original directory
  ORIG_DIR=$PWD

  # switch to the desired install directory
  cd $CMAKE_INSTALL_DIR

  # download the desired version of cmake
  CMAKE=cmake-$CMAKE_VER-Linux-x86_64
  wget https://github.com/Kitware/CMake/releases/download/v$CMAKE_VER/$CMAKE.tar.gz
  tar -xvzf $CMAKE.tar.gz

  # create softlinks to the desired binaries
  ln -s $CMAKE/bin/cmake cmake
  ln -s $CMAKE/bin/ctest ctest

  if [[ $NOPROMPT = false ]]
  then
    read -p "${BEGIN}Would you like to add $CMAKE_INSTALL_DIR to your working path by appending to your .bash_profile file? [y/n] ${END}"
    echo ""
  fi

  if [[ $REPLY =~ ^[Yy]$ ]] || [[ $NOPROMPT = true ]]
  then
    echo "export PATH=$PATH:$CMAKE_INSTALL_DIR" >> $HOME/.bash_profile
    NEED_BASH_PROFILE=true
  fi

  cd $ORIG_DIR
fi
echo ""

#
# Setup python ################################################################
#

clear
if [[ $NOPROMPT = false ]]
then
    read -p "${BEGIN}Tooling for this project requires use of Python 3.  Would you \
    like to install it now? [y/n]${END}"
    echo ""
fi

if [[ $REPLY =~ ^[Yy]$ ]] || [[ $NOPROMPT = true ]]
then
    echo "${BEGIN}Installing python...${END}"
    sudo apt-get install python3 python3-pip -y
fi

if [[ $NOPROMPT = false ]]
then
    read -p "${BEGIN}For convenience the deps tool can be installed to your system \
Alternatively you can install its dependencies using pip and call it directly \
via tools/deps/bin/deps.  Would you like to install it? [y/n]${END}"
    echo ""
fi

if [[ $REPLY =~ ^[Yy]$ ]] || [[ $NOPROMPT = true ]]
then
    echo "${BEGIN}Installing deps tool...${END}"
    pip3 install setuptools
    ORIG_DIR=$PWD
    cd tools/deps
    sudo python3 setup.py install
    cd $ORIG_DIR
fi

#
# Setup softlinks #############################################################
#

clear
if [[ $NOPROMPT = false ]]
then
    read -p "${BEGIN}Based on your platform we can create softlinks to common tools and utilities \
to reduce the amount of typing you need to do.  These will be linked into \
the project root, for example ./deps or ./build.  Would you like to make these \
softlinks? [y/n] ${END}"
    echo ""
fi

if [[ $REPLY =~ ^[Yy]$ ]] || [[ $NOPROMPT = true ]]
then
  echo "${BEGIN}Creating links...${END}"
  ln -s ./tools/build/linux/cbuild.sh ./build
  ln -s ./tools/build/linux/cbench.sh ./bench
  echo ""
fi

#
# Finished ####################################################################
#

clear
echo "${FINAL}Project has been bootstrapped!  Next you should run \"deps install\" and then you will be able to run \"./build\"${END}"
if [[ $NEED_BASH_PROFILE = true ]]
then
    echo "${ALERT}You will need to run \"source $HOME/.bash_profile\" or reopen your terminal before cmake is available! [enter]${END}"
fi

echo ""
