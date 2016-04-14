#include <sys/socket.h> // Core socket functions and data structures
#include <netinet/in.h> // AF_INET and AF_INET6 address families and their corresponding protocol families
#include <arpa/inet.h>  // Core socket functions and data structures (eg: inet_addr)
#include <netdb.h>      // Functions for translating protocol names and host names into numeric addresses
#include <unistd.h>     // close()
#include <string.h>     // strlen
#include <string>       // string

#include "StreamSocket.hh"

using namespace std;

StreamSocket::StreamSocket (int protocol_, Logger* logger_) {
  sock     = -1;
  protocol = protocol_;
  port     = 0;
  logger   = logger_;
}

StreamSocket& StreamSocket::create () {
  // Create socket if not already created
  if (sock == -1) {
    sock = socket(protocol, SOCK_STREAM, 0);
    // Exit if failure
    if (sock < 0) {
      logger->messageFromCode("ERR_SOCKET_CREATE");
      exit(1);
    }
    logger->info("new socket created...");
  }
  // Socket already created
  else {
    logger->messageFromCode("ERR_SOCKET_ALREADY_CREATED");
  }

  return *this;
}

StreamSocket& StreamSocket::attach (int port_) {
  // Setup the port value
  port = port_;

  // https://www.mkssoftware.com/docs/man3/memset.3.asp
  memset((char *) &serverAddr, sizeof(serverAddr), 0);

  serverAddr.sin_family      = protocol;
  serverAddr.sin_port        = htons(port); // host to network short
  serverAddr.sin_addr.s_addr = INADDR_ANY;  // INADDR_ANY -> any Internet interface

  int status = bind(sock, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

  if (status < 0) {
    logger->messageFromCode("ERR_SOCKET_BIND");
    StreamSocket::quit();
  }

  logger->info("socket attached to '" + to_string(INADDR_ANY) + ":" + to_string(port) + "...");
  return *this;
}

StreamSocket& StreamSocket::lookOut (int maximumPendingRequestsQueueSize_) {
  int status = listen(sock, maximumPendingRequestsQueueSize_);

  if (status < 0) {
    logger->messageFromCode("ERR_SOCKET_LISTEN");
    StreamSocket::quit();
  }

  logger->info("socket waiting for client connections (queueSize: " + to_string(maximumPendingRequestsQueueSize_) + ")...");
}

StreamSocket& StreamSocket::acquire () {
  int size, status;

  size   = sizeof(struct sockaddr_in);
  status = accept(sock, (struct sockaddr *) &clientAddr, (socklen_t*) &size);

  if (status < 0) {
    logger->messageFromCode("ERR_SOCKET_ACCEPT");
    StreamSocket::quit();
  }

  logger->info("request from client acquired...");
  return *this;
}

StreamSocket& StreamSocket::deliver (const void* buffer_, size_t length_, int flags_) {
  // @todo ne passer qu'un message en paramètre. Faire la transformation buffer and co
  // que localement à cette méthode pour masquer la bullshit !
  int status = send(sock, buffer_, length_, flags_);

  if (status < 0) {
    logger->messageFromCode("ERR_SOCKET_SEND");
    StreamSocket::quit();
  }

  logger->info("a message has been sent on this socket...");
  return *this;
}

void StreamSocket::quit () {
  if (sock > 0) {
    // Close socket
    close(sock);
    // Reset integer value
    sock = -1;
  }

  logger->info("socket closed...");
  exit(1);
}



