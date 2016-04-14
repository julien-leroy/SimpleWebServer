#include <iostream> // std::cout
#include <cstring>  // std::string, std::to_string

#include "helpers/Logger.hh"
#include "socket/StreamSocket.hh"

int main(int argc, char *argv[]) {

  const char *buffer[256];
  size_t length = 255;

  /* Logger instance */
  Logger *logger = new Logger();

  /* StreamSocket instance */
  StreamSocket socket = StreamSocket(AF_INET, logger);

  socket.create()
        .attach(8888)
        .lookOut(5);
  socket.acquire();
  socket.deliver(buffer, length, 0)
        .quit();

  return 0;
}
