#!/bin/bash

MAKE_ENTRY_POINT="main"
MAKE_ROOT_PATH=`pwd`

function makeBuild() {
  #local FLAGS="-W -Wall -Werror -pedantic -pthread -std=c++11"
  local FLAGS="-std=c++11"

  clear
  echo "BUILD"
  echo "------------------------------------------------------"
  g++ -c $2/src/helpers/Logger.cc $FLAGS
  g++ -c $2/src/socket/TCPSocket.cc $FLAGS
  g++ -c $2/src/main.cc $FLAGS
  g++ -o $1 $2/Logger.o $2/TCPSocket.o $2/main.o $FLAGS
  mv $1 $2/bin
  rm *.o
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
