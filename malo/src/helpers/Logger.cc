#include <iostream> // std::cout
#include <string>   // std::string, std::to_string

#include "Logger.hh"

using namespace std;

Logger::Logger () {}

void Logger::console (string message_) {
  cout << message_ << endl;
}

void Logger::info (string message_) {
  this->console(message_);
}

void Logger::error (string message_) {
  this->console(message_);
}

void Logger::debug (string message_) {
  this->console(message_);
}

void Logger::messageFromCode (string code_) {
  const int LINES = 8; // @todo beuurk
  const int CELLS = 2; // @todo beuurk
  string messages[LINES][CELLS] = {
    { "ERR_UNKNOWN_ERR",            "ERR: unknown error" },
    { "ERR_SOCKET_CREATE",          "ERR: Could not create socket" },
    { "ERR_SOCKET_ALREADY_CREATED", "ERR: socket instance already created" },
    { "ERR_SOCKET_BIND",            "ERR: can't bind addresse:port to this socket" },
    { "ERR_SOCKET_LISTEN",          "ERR: can't listen to client connections" },
    { "ERR_SOCKET_ACCEPT",          "ERR: can't accept this client connection" },
    { "ERR_SOCKET_SEND",            "ERR: could not send a message throw this socket" },
    { "ERR_OUT_OF_MEMORY",          "ERR: out of memory..." },
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
  this->console(message);
}

string Logger::toString (int text_) {
  return to_string(text_);
}

