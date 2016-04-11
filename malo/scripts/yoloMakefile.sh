#!/bin/bash

clear

echo "BUILD"
echo "------------------------------------------------------"
PJ_EXE_NAME="sws"
PJ_ROOT_PATH=`pwd`
PJ_SRC_DIR="$PJ_ROOT_PATH/src"
PJ_INCLUDED_FILES="$PJ_SRC_DIR/server.cc $PJ_SRC_DIR/helpers/Logger.hh"
g++ -c $PJ_SRC_DIR/helpers/Logger.cc
g++ -c $PJ_SRC_DIR/server.cc
g++ -o $PJ_EXE_NAME $PJ_ROOT_PATH/Logger.o $PJ_ROOT_PATH/server.o -std=c++11
#g++ -g -W -Wall -Werror -pedantic -pthread -std=c++11 $PJ_INCLUDED_FILES -o $PJ_EXE_NAME
echo ""

if [ -f "$PJ_ROOT_PATH/$PJ_EXE_NAME" ]; then
  echo "RUN"
  echo "------------------------------------------------------"
  IP="192.168.56.101"
  PORT=8888
  ./$PJ_EXE_NAME $IP $PORT
fi
