#include <string>
#include "Logger.h"

using namespace std;

Logger::Logger() {
  // Nothing to do here
}

virtual ~Logger() {
    // Do some stuff here with non-static data members...
}

void Logger::print (string message) {
  cout << message << endl;
}

void Logger::info (string message) {
  this->print(message);
}

void Logger::error (string code) {
  const int LINES = 8; // @todo beuurk
  const int CELLS = 2; // @todo beuurk
  string errors[LINES][CELLS] = {
    { "ERR_UNKNOWN_ERR",        "unknown error..." },
    { "ERR_NO_PORT",            "no port provided..." },
    { "ERR_SOCKET_OPEN",        "Socket can't be opened..." },
    { "ERR_SOCKET_BIND",        "binding failed..." },
    { "ERR_SOCKET_ACCEPT",      "error on accept..." },
    { "ERR_SOCKET_READ",        "error on socket reading..." },
    { "ERR_SOCKET_WRITE",       "error on socket writing..." },
    { "ERR_OUT_OF_MEMORY",      "out of memory..." },
  };
  string message = errors[0][1];
  int i, j;

  for (i = 0; i < LINES; ++i) {
    for (j = 0; j < CELLS; ++j) {
      if (errors[i][0] == code) {
        message = errors[i][j];
      }
    }
  }

  this->print("ERR: " + message);
}

void Logger::debug (string message) {
  this->print(message);
}

