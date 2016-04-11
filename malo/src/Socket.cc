#include <sys/types.h>
#include <sys/socket.h>
#include <string>
#include "Socket.hh"

using namespace std;

Socket::Socket (Logger* logger) {
  logger = logger;
}

int Socket::open (int family, int type, int port) {

  // // Error: no port specified
  // if (argc < 2) {
  //   logger->error("ERR_NO_PORT");
  //   exit(1);
  // }

  cout << "coucou cay moa" << endl;
}

void Socket::bind (int tsocket, int family, int port) {
  cout << "coucou cay moa" << endl;
}

void Socket::listen (int tsocket, int port) {
  cout << "coucou cay moa" << endl;
}

int Socket::accept (int tsocket) {
  cout << "coucou cay moa" << endl;
}

int Socket::read (int request, void* message, int buffer) {
  cout << "coucou cay moa" << endl;
}

int Socket::write (void *message, int connection, int request) {
  cout << "coucou cay moa" << endl;
}

void Socket::close (int tsocket, int request) {
  cout << "coucou cay moa" << endl;
}



