#include <iostream> // std::cout
#include <cstring>  // std::string, std::to_string

#include "helpers/Logger.hh"
#include "socket/StreamSocket.hh"

int main(int argc, char *argv[]) {

  size_t length = 255;
  int client;

  /* Logger instance */
  Logger *logger = new Logger();

  /* StreamSocket instance */
  StreamSocket socket = StreamSocket(AF_INET, logger);

  socket.create()
        .attach(8888)
        .lookOut(5);

  while (1) {
    client = socket.acquire();
    if (socket.receive(client)) {
      socket.deliver(client, "coucou client !")
            .disconnect(client);
    }
  }

  socket.quit();

  return 0;
}
