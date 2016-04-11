// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <netinet/in.h>

#include <iostream> // std::cout
#include <string>   // std::string, std::to_string

#include "helpers/Logger.hh"
#include "Socket.hh"

using namespace std; // @todo remove


int main(int argc, char *argv[]) {

  /* Logger instance */
  Logger* logger = new Logger();

  const int BUFFER = 255;

  int port = atoi(argv[1]);
  char *message[256];

  /* Socket instance */
  Socket* StreamSocket = new Socket(AF_INET, SOCK_STREAM, port, logger);

  StreamSocket->open();

  // StreamSocket->bind();

  // StreamSocket->listen();

  // int request = StreamSocket->accept();

  // int connection = StreamSocket->read(request, message, BUFFER);

  // int answer = StreamSocket->write(message, connection, request);

  // logger->debug("info: " + to_string(answer));

  // StreamSocket->close(request);




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
