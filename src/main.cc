#include <iostream> // std::cout
#include <cstring>  // std::string, std::to_string
#include <thread> // @todo externalize the thread management

#include "helpers/Logger.hh"
#include "socket/TCPSocket.hh"

using namespace std;

// @todo refactor, déplacer cette déclaration de méthode ailleurs
void post(TCPSocket socket, int client);
void post(TCPSocket socket, int client) {
  // simulate expensive operation
  string response = socket.getRessource(); // @todo refactor -> déplacer cette méthode dans une classe serveur, ce n'est pas le rôle du socket !
  socket.deliver(client, response)
        .disconnect(client);
}

int main(int argc, char *argv[]) {

  size_t length = 255;
  int client;

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

      // Constructs the new thread and runs it. Does not block execution.
      thread t1(post, socket, client);

      // Makes the main thread wait for the new thread to finish execution, therefore blocks its own execution.
      t1.join();

    }

  }

  socket.quit();

  return EXIT_SUCCESS;
}

