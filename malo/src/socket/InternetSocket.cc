// #include <cstdio>
// #include <cstdlib>
// #include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <cstring>

#include "InternetSocket.hh"

InternetSocket::InternetSocket (int family, int type, int port, Logger* logger) {
  this->family = family;
  this->type   = type;
  this->port   = port;
  this->logger = logger;

  this->logger->info("New InternetSocket class instance created...");
}

void InternetSocket::open () {
  int SocketInstance = socket(this->family, this->type, 0);

  if (SocketInstance == -1) {
    this->logger->error("ERR_SOCKET_OPEN");
    exit(1);
  }
  this->InternetSocketInstance = SocketInstance;
  this->logger->info("InternetSocket of family " + logger->toString(this->family) + " and type " + logger->toString(this->type) + " is opened...");
}

/*
@GUILLAUME -> HERE
*/
void InternetSocket::bindName () {
  struct sockaddr_in serv_addr;
  int BindedSocket;

  // see: https://www.mkssoftware.com/docs/man3/bzero.3.asp
  // see: https://www.mkssoftware.com/docs/man3/memset.3.asp
  // ex memset: memset(someobject, size_of_object, 0);
  memset((char *) &serv_addr, sizeof(serv_addr), 0);

  serv_addr.sin_family      = this->family;
  serv_addr.sin_port        = htons(this->port); // host to network short
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); // htonl -> host to network long | INADDR_ANY -> any Internet interface

  BindedSocket = bind(this->InternetSocketInstance, (struct sockaddr *) &serv_addr, sizeof(serv_addr));

  if (BindedSocket == -1) {
    this->logger->error("ERR_SOCKET_BIND");
    exit(1);
  }

  this->logger->info("InternetSocket binded to '" + std::to_string(INADDR_ANY) + ":" + std::to_string(this->port) + "...");
}

void InternetSocket::listenToClient (int maxRequestsToQueue) {
  listen(this->InternetSocketInstance, maxRequestsToQueue);
  this->logger->info("Server ready for accepting client connection requests (MAX " + std::to_string(maxRequestsToQueue) + ")...");
}

/*
@GUILLAUME -> HERE
*/
int InternetSocket::acceptConnection () {
  // int request = accept(socket, (struct sockaddr *) &cli_addr, sizeof(cli_addr));
  // if (request < 0) {
  //   this->logger->error("ERR_SOCKET_ACCEPT");
  //   exit(1);
  // }
  // this->logger->info("InternetSocket accepted for request");
  // return request;
  return 1;
}

int InternetSocket::read (int request, void* message, int buffer) {
  // int connection = read(request, message, buffer);
  // if (connection < 0) {
  //   this->logger->error("ERR_SOCKET_READ");
  //   exit(1);
  // }
  // this->logger->info("A connection has been established");
  // return connection;
  return 1;
}

int InternetSocket::write (void *message, int connection, int request) {
  // write(1, message, connection);
  // int answer = write(request, "I got your message", 18);
  // if (answer < 0) {
  //   this->logger->error("ERR_SOCKET_WRITE");
  //   exit(1);
  // }
  // this->logger->info("Response sent successfully!");
  // return answer;
  return 1;
}

void InternetSocket::close (int request) {
  // close(request);
  // close(this->InternetSocketInstance);
  // this->logger->info("InternetSocket closed...");
}



