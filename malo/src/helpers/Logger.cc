/* -*- C++ -*- */

/****************************************************************************
** Copyright (C) 2016-2018 Malo Blanchard
**
** This file is part of the SimpleWebServer project
**
** This file may be distributed under the terms of the SimpleWebServer
** license as defined by SimpleWebServer and appearing in the file
** LICENSE included in the packaging of this file.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
** See https://github.com/Izin/sws/master/LICENSE for licensing information.
**
** Contact github@maloblanchard.com if any conditions of this licensing are
** not clear to you.
**/

#include <iostream> // std::cout
#include <string>   // std::string, std::to_string

#include "Logger.hh"

using namespace std;

Logger::Logger () {}

void Logger::console (string message_) {
  cout << message_ << endl;
}

void Logger::info (string message_) {
  this->console("INF: " + message_);
}

void Logger::error (string message_) {
  this->console("ERR: " + message_);
}

void Logger::debug (string message_) {
  this->console("DEB: " + message_);
}

void Logger::messageFromCode (string code_) {
  const int LINES = 8; // @todo beuurk
  const int CELLS = 2; // @todo beuurk
  string messages[LINES][CELLS] = {
    { "ERR_UNKNOWN_ERR",            "unknown error" },
    { "ERR_SOCKET_CREATE",          "Could not create socket" },
    { "ERR_SOCKET_ALREADY_CREATED", "socket instance already created" },
    { "ERR_SOCKET_BIND",            "can't bind addresse:port to this socket" },
    { "ERR_SOCKET_LISTEN",          "can't listen to client connections" },
    { "ERR_SOCKET_ACCEPT",          "can't accept this client connection" },
    { "ERR_SOCKET_SEND",            "could not send a message throw this socket" },
    { "ERR_OUT_OF_MEMORY",          "out of memory..." },
  };
  string message = messages[0][1];
  int i, j;
  for (i = 0; i < LINES; ++i) {
    for (j = 0; j < CELLS; ++j) {
      if (messages[i][0] == code_) {
        message = messages[i][j];
      }
    }
  }
  this->error(message);
}

string Logger::toString (int n_) {
  return to_string(n_);
}

