#include <sys/types.h>
#include <sys/socket.h>

#include "Socket.hh"

Socket::Socket (int family, int type, int port, Logger* logger) {
  this->family = family;
  this->type   = type;
  this->port   = port;
  this->logger = logger;

  this->logger->info("Class instance created...");
}

void Socket::open () {
  //int instance = socket(this->family, this->type, 0);
  int instance = 0;

  if (instance == -1) {
    this->logger->error("ERR_SOCKET_OPEN");
    exit(1);
  }
  this->socket = instance;
  this->logger->info("Socket of family " + logger->toString(this->family) + " and type " + logger->toString(this->type) + " is opened...");
}

void Socket::bind () {
  // Use to initializing the structs, like sock_addr_in, or char buffers
  // (that we used to send data back and forth between client and server)
  // see: https://www.mkssoftware.com/docs/man3/bzero.3.asp
  // see: https://www.mkssoftware.com/docs/man3/memset.3.asp
  // ex memset: memset(someobject, size_of_object, 0);
  // ??? que fait bzero ici ?
  // memset((char *) this->socket.serv_addr, sizeof(serv_addr), 0);

  // this->socket.serv_addr.sin_family      = this->family;
  // this->socket.serv_addr.sin_addr.s_addr = INADDR_ANY;
  // this->socket.serv_addr.sin_port        = htons(this->port);

  // if (bind(this->socket, (struct sockaddr *) &this->socket.serv_addr, sizeof(this->socket.serv_addr)) == -1) {
  //   this->logger->error("ERR_SOCKET_BIND");
  //   exit(1);
  // }
  // this->logger->info("Socket binded to '" + to_string(INADDR_ANY) + ":" + to_string(PORT) + "...");
  // this->logger->info("bind");
}

void Socket::listen () {
  // listen(socket, 5);
  // this->logger->info("Server started and listening to port n°" + to_string(this->port) + "...");
}

int Socket::accept () {
  // int request = accept(socket, (struct sockaddr *) &cli_addr, sizeof(cli_addr));
  // if (request < 0) {
  //   this->logger->error("ERR_SOCKET_ACCEPT");
  //   exit(1);
  // }
  // this->logger->info("Socket accepted for request");
  // return request;
  return 1;
}

int Socket::read (int request, void* message, int buffer) {
  // int connection = read(request, message, buffer);
  // if (connection < 0) {
  //   this->logger->error("ERR_SOCKET_READ");
  //   exit(1);
  // }
  // this->logger->info("A connection has been established");
  // return connection;
  return 1;
}

int Socket::write (void *message, int connection, int request) {
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

void Socket::close (int request) {
  // close(request);
  // close(this->socket);
  // this->logger->info("Socket closed...");
}



