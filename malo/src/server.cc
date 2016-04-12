#include <iostream> // std::cout
#include <cstring>  // std::string, std::to_string

#include "helpers/Logger.hh"
#include "socket/InternetSocket.hh"


int main(int argc, char *argv[]) {

  /* Logger instance */
  Logger* logger = new Logger();

  const int BUFFER = 255;

  int port = atoi(argv[1]);
  char *message[256];

  /* InternetSocket instance */
  InternetSocket* ISocket = new InternetSocket(AF_INET, SOCK_STREAM, port, logger);

  ISocket->open();

  ISocket->bindName();

  ISocket->listenToClient(5);

  int request = ISocket->acceptConnection();

  // int connection = ISocket->read(request, message, BUFFER);

  // int answer = ISocket->write(message, connection, request);

  // logger->debug("info: " + to_string(answer));

  // ISocket->close(request);




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
