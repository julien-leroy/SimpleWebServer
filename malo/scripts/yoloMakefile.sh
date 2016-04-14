#!/bin/bash

clear

echo "BUILD"
echo "------------------------------------------------------"
PJ_CXX_FLAGS="-W -Wall -Werror -pedantic -pthread -std=c++11"
PJ_BASIC_CXX_FLAGS="-std=c++11"
PJ_EXE_NAME="sws"
PJ_ROOT_PATH=`pwd`
PJ_SRC_DIR="$PJ_ROOT_PATH/src"
PJ_INCLUDED_FILES="$PJ_SRC_DIR/server.cc $PJ_SRC_DIR/helpers/Logger.hh"

g++ -c $PJ_SRC_DIR/helpers/Logger.cc $PJ_BASIC_CXX_FLAGS
g++ -c $PJ_SRC_DIR/socket/StreamSocket.cc $PJ_BASIC_CXX_FLAGS
g++ -c $PJ_SRC_DIR/server.cc $PJ_BASIC_CXX_FLAGS
g++ -o $PJ_EXE_NAME $PJ_ROOT_PATH/Logger.o $PJ_ROOT_PATH/StreamSocket.o $PJ_ROOT_PATH/server.o $PJ_BASIC_CXX_FLAGS

echo ""

if [ -f "$PJ_ROOT_PATH/$PJ_EXE_NAME" ]; then
  echo "RUN"
  echo "------------------------------------------------------"
  ./$PJ_EXE_NAME
fi
