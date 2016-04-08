//#include <sys/types.h>
//#include <sys/socket.h>

#include "socket.h"

int createSocket(int family, int type, Logger *logger) {
  int tsocket = socket(family, type, 0);

  if (tsocket == -1) {
    logger->error("ERR_SOCKET_OPEN");
    exit(1);
  }

  return tsocket;
}

void bindSocket(int tsocket, int family, int port, Logger *logger) {
  // Use to initializing the structs, like sock_addr_in, or char buffers
  // (that we used to send data back and forth between client and server)
  // see: https://www.mkssoftware.com/docs/man3/bzero.3.asp
  // see: https://www.mkssoftware.com/docs/man3/memset.3.asp
  // ex memset: memset(someobject, size_of_object, 0);
  // ??? que fait bzero ici ?
  memset((char *) tsocket.serv_addr, sizeof(serv_addr), 0);

  tsocket.serv_addr.sin_family      = family;
  tsocket.serv_addr.sin_addr.s_addr = INADDR_ANY;
  tsocket.serv_addr.sin_port        = htons(port);

  if (bind(tsocket, (struct sockaddr *) &tsocket.serv_addr, sizeof(tsocket.serv_addr)) == -1) {
    logger->error("ERR_SOCKET_BIND");
    exit(1);
  }
  logger->info("Socket binded to '" + to_string(INADDR_ANY) + ":" + to_string(PORT) + "...");
}

void listenSocket(int tsocket, int port, Logger *logger) {

  listen(tsocket,5);

  logger->info("Server started and listening to port n°" + to_string(port) + "...");
}

int acceptSocket(int tsocket, Logger *logger) {
  int request = accept(tsocket, (struct sockaddr *) &cli_addr, sizeof(cli_addr));

  if (request < 0) {
    logger->error("ERR_SOCKET_ACCEPT");
    exit(1);
  }

  logger->info("Socket accepted for request");

  return request;
}

int readSocket(int request, void *message, int buffer, Logger *logger) {
  int connection = read(request, message, buffer);

  if (connection < 0) {
    logger->error("ERR_SOCKET_READ");
    exit(1);
  }

  logger->info("A connection has been established");

  return connection;
}

int writeSocket(void *message, int connection, int request, Logger *logger) {
  write(1, message, connection);
  int answer = write(request,"I got your message",18);

  if (answer < 0) {
    logger->error("ERR_SOCKET_WRITE");
    exit(1);
  }

  logger->info("Response sent successfully!");

  return answer;
}

void closeSocket(int tsocket, int request, Logger *logger) {

  close(request);
  close(tsocket);

  logger->info("Socket closed...");
}
