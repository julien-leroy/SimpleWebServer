#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h> // @todo remove?
#include <sys/socket.h> // @todo remove?
#include <netinet/in.h>

#include <string>
#include <iostream>


#include "helpers/Logger.h"
#include "socket.h"

using namespace std;


int main(int argc, char *argv[]) {

  /* Logger instance */
  Logger * logger = new Logger();

  // No port specified
  if (argc < 2) {
    logger->error("ERR_NO_PORT");
    exit(1);
  }

  // new Socket(port, protocol, type, logger)
  // @todo

  // Socket properties
  const int family = AF_INET;
  const int BUFFER = 255;

  int tsocket, request, answer, servlen, connection, PORT = atoi(argv[1]);
  socklen_t clilen;
  char *message[256];

  // see: http://www.cas.mcmaster.ca/~qiao/courses/cs3mh3/tutorials/socket.html
  // struct sockaddr_in {
  //   short           sin_family;  /* AF_INET */
  //   u_short         sin_port;    /* 16-bit port number */
  //   struct in_addr  sin_addr;
  //   char            sin_zero[8]; /* unused */
  // };
  struct sockaddr_in cli_addr, serv_addr; // /!\ ATTENTION !! à@revoirDépendance !

  tsocket = socket(AF_INET, SOCK_STREAM, 0);
  //socket = createSocket(family, SOCK_STREAM, logger);


  bindSocket(tsocket, family, PORT, logger);

  listenSocket(tsocket, PORT, logger);

  request = acceptSocket(tsocket, logger);

  connection = readSocket(request, message, BUFFER, logger);

  answer = writeSocket(message, connection, request, logger);

  closeSocket(tsocket, request, logger);


  return 0;
}
