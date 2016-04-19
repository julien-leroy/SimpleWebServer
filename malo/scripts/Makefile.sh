#!/bin/bash

## ****************************************************************************
## Copyright (c) 2016 - 2018, Malo Blanchard
##
## This file is part of the SimpleWebServer project
##
## This file may be distributed under the terms of the SimpleWebServer
## license as defined by SimpleWebServer and appearing in the file
## LICENSE included in the packaging of this file.
##
## This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
## WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
##
## See https://github.com/Izin/sws/master/LICENSE for licensing information.
##
## Contact github@maloblanchard.com if any conditions of this licensing are
## not clear to you.
##


MAKE_ENTRY_POINT="main"
MAKE_ROOT_PATH=`pwd`

function makeBuild() {
  #local FLAGS="-W -Wall -Werror -pedantic -pthread -std=c++11"
  local FLAGS="-std=c++11"

  clear
  echo "BUILD"
  echo "------------------------------------------------------"
  g++ -c $2/src/helpers/Logger.cc $FLAGS
  g++ -c $2/src/socket/StreamSocket.cc $FLAGS
  g++ -c $2/src/main.cc $FLAGS
  g++ -o $1 $2/Logger.o $2/StreamSocket.o $2/main.o $FLAGS
  return 0
}

function makeRun() {
  if [ ! -f "$2/$1" ]; then
    return 1;
  fi

  echo ""
  echo "RUN"
  echo "------------------------------------------------------"
  ./$1
  return 0
}

# main
makeBuild "$MAKE_ENTRY_POINT" "$MAKE_ROOT_PATH"
makeRun "$MAKE_ENTRY_POINT" "$MAKE_ROOT_PATH"
