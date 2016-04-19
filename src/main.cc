#include <iostream> // std::cout
#include <cstring>  // std::string, std::to_string

#include "helpers/Logger.hh"
#include "socket/TCPSocket.hh"

using namespace std;

int main(int argc, char *argv[]) {

  size_t length = 255;
  int client;
  string request, response;

  /* Logger instance */
  Logger *logger = new Logger(true);

  /* TCPSocket instance */
  TCPSocket socket = TCPSocket(SOCK_STREAM, AF_INET, logger);

  socket.create()
        .attach(8888)
        .lookOut(5);

  while (true) {
    client = socket.acquire();

    if (socket.receive(client)) {
      response = socket.getRessource(); // @todo refactor -> déplacer cette méthode dans une classe serveur, ce n'est pas le rôle du socket !
      socket.deliver(client, response)
            .disconnect(client);
    }

  }

  socket.quit();

  return EXIT_SUCCESS;
}
