#!/bin/bash

clear

echo "BUILD"
echo "------------------------------------------------------"
PROJECT_ROOT=`pwd`
PROJECT_SRC_DIR="$PROJECT_ROOT/src"
g++ $PROJECT_SRC_DIR/main.cc -o main                          # light
#g++ $PROJECT_SRC_DIR/main.cc -std=c++11 -g -pthread -o main   # heavy
echo "Done!"

echo ""
echo "RUN"
echo "------------------------------------------------------"

IP="192.168.56.101"
PORT=8888
./main $IP $PORT
