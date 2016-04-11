#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string>
#include <iostream>


#include "helpers/Logger.hh"
#include "Socket.hh"
//#include "socket.h"

using namespace std;


int main(int argc, char *argv[]) {

  /* Logger instance */
  Logger* logger = new Logger();

  logger->debug("test");

  exit(0);

  /* Socket instance */
  Socket* socket = new Socket(logger);

  // Socket properties
  const int family = AF_INET;
  const int BUFFER = 255;

  int tsocket, request, answer, servlen, connection, PORT = atoi(argv[1]);
  socklen_t clilen;
  char *message[256];

  socket->open(10, 10, 8888);

  // see: http://www.cas.mcmaster.ca/~qiao/courses/cs3mh3/tutorials/socket.html
  // struct sockaddr_in {
  //   short           sin_family;  /* AF_INET */
  //   u_short         sin_port;    /* 16-bit port number */
  //   struct in_addr  sin_addr;
  //   char            sin_zero[8]; /* unused */
  // };
  // struct sockaddr_in cli_addr, serv_addr; // /!\ ATTENTION !! à@revoirDépendance !

  // socket = createSocket(family, SOCK_STREAM, logger);

  // bindSocket(tsocket, family, PORT, logger);

  // listenSocket(tsocket, PORT, logger);

  // request = acceptSocket(tsocket, logger);

  // connection = readSocket(request, message, BUFFER, logger);

  // answer = writeSocket(message, connection, request, logger);

  // closeSocket(tsocket, request, logger);




  // try
  //   {
  //       boost::property_tree::ptree pt;
  //       boost::property_tree::read_json(config, pt);

  //       boost::property_tree::ptree::const_iterator it;
  //       boost::property_tree::ptree libs = pt.get_child("libs");
  //       boost::property_tree::ptree::const_iterator libsit;

  //       for (libsit = libs.begin(); libsit != libs.end(); ++libsit)
  //       {
  //           std::string lib = libsit->second.get<std::string>("");
  //           std::cout << "Need lib " << lib << std::endl;

  //           loadlib(lib, root);
  //       }
  //   }
  //   catch (std::exception const& e)
  //   {
  //       std::cerr << e.what() << std::endl;
  //   }

  return 0;
}
