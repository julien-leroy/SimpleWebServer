#include <sys/types.h>
#include <sys/socket.h>

#include "Socket.hh"

using namespace std;

Socket::Socket (Logger* logger) {
  logger = logger;
}

virtual Socket::~Socket () {
  // Do some stuff here with non-static data members...
}

int open(int family, int type, int port) {

  // // Error: no port specified
  // if (argc < 2) {
  //   logger->error("ERR_NO_PORT");
  //   exit(1);
  // }

  cout << "coucou cay moa" << endl;
}

void bind(int tsocket, int family, int port) {
  cout << "coucou cay moa" << endl;
}

void listen(int tsocket, int port) {
  cout << "coucou cay moa" << endl;
}

int accept(int tsocket) {
  cout << "coucou cay moa" << endl;
}

int read(int request, void* message, int buffer) {
  cout << "coucou cay moa" << endl;
}

int write(void *message, int connection, int request) {
  cout << "coucou cay moa" << endl;
}

void close(int tsocket, int request) {
  cout << "coucou cay moa" << endl;
}



