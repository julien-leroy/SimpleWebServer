#include <iostream> // std::cout
#include <string>   // std::string, std::to_string

#include "Logger.hh"

using namespace std;

Logger::Logger (bool isProduction_) {
  isProduction = isProduction_;
}

void Logger::console (string message_) {
  cout << message_ << endl;
}

void Logger::info (string message_) {
  if (isProduction) {
    return;
  }
  this->console("INF: " + message_);
}

void Logger::error (string message_) {
  if (isProduction) {
    return;
  }
  this->console("ERR: " + message_);
}

void Logger::debug (string message_) {
  if (isProduction) {
    return;
  }
  this->console("DEB: " + message_);
}

void Logger::messageFromCode (string code_) {
  if (isProduction) {
    return;
  }
  const int LINES = 10; // @todo beuurk
  const int CELLS = 2; // @todo beuurk
  // @todo remplacer par map<string, string> mime;
  // https://github.com/konteck/wpp/blob/master/web%2B%2B.hpp
  //ex: mime["jpg"] = "image/jpeg";
  string messages[LINES][CELLS] = {
    { "ERR_UNKNOWN_ERR",                "unknown error" },
    { "ERR_SOCKET_CREATE",              "Could not create socket" },
    { "ERR_SOCKET_ALREADY_CREATED",     "socket instance already created" },
    { "ERR_SOCKET_BIND",                "can't bind addresse:port to this socket" },
    { "ERR_SOCKET_LISTEN",              "can't listen to client connections" },
    { "ERR_SOCKET_ACCEPT",              "can't accept this client connection" },
    { "ERR_SOCKET_CANNOT_RECEIVE",      "can't receive the client request" },
    { "ERR_SOCKET_CLIENT_DISCONNECTED", "client disconnected from the socket"},
    { "ERR_SOCKET_SEND",                "could not send a message throw this socket" },
    { "ERR_OUT_OF_MEMORY",              "out of memory..." },
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

