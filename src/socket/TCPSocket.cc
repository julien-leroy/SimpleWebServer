#include <sys/socket.h> // Core socket functions and data structures
#include <netinet/in.h> // AF_INET and AF_INET6 address families and their corresponding protocol families
#include <arpa/inet.h>  // Core socket functions and data structures (eg: inet_addr)
#include <netdb.h>      // Functions for translating protocol names and host names into numeric addresses
#include <unistd.h>     // close()
#include <string.h>     // strlen
#include <string>       // string

#include <sys/stat.h> // @todo déplacer ça dans une classe "File"

#include "../helpers/utils.cpp"
#include "TCPSocket.hh"

using namespace std;

TCPSocket::TCPSocket (int type_, int protocol_, Logger* logger_) {
  sock     = -1;
  type     = type_;
  protocol = protocol_;
  port     = 0;
  logger   = logger_;
}

TCPSocket& TCPSocket::create () {
  if (sock > -1) {
    logger->messageFromCode("ERR_SOCKET_ALREADY_CREATED");
    return *this;
  }

  sock = socket(protocol, type, 0);

  if (sock < 0) {
    logger->messageFromCode("ERR_SOCKET_CREATE");
    exit(1);
  }

  logger->info("new socket created...");
  return *this;
}

TCPSocket& TCPSocket::attach (int port_) {
  port = port_;

  // https://www.mkssoftware.com/docs/man3/memset.3.asp
  memset(&server, 0, sizeof(server));

  server.sin_family      = protocol;
  server.sin_port        = htons(port); // host to network short
  server.sin_addr.s_addr = INADDR_ANY;  // Any Internet interface

  if (bind(sock, (struct sockaddr *) &server, sizeof(server)) < 0) {
    logger->messageFromCode("ERR_SOCKET_BIND");
    TCPSocket::quit();
  }

  logger->info("socket listening on port " + to_string(port) + "...");
  return *this;
}

TCPSocket& TCPSocket::lookOut (int maximumPendingRequestsQueueSize_) {

  if (listen(sock, maximumPendingRequestsQueueSize_) < 0) {
    logger->messageFromCode("ERR_SOCKET_LISTEN");
    TCPSocket::quit();
  }

  logger->info("socket waiting for client connections (queueSize: " + to_string(maximumPendingRequestsQueueSize_) + ")...");
  return *this;
}

int TCPSocket::acquire () {
  int size, client;
  socklen_t length = sizeof(client);

  memset(&client, 0, sizeof(client));

  size    = sizeof(struct sockaddr_in);
  client  = accept(sock, (struct sockaddr*) &client, &length);

  if (client < 0) {
    logger->messageFromCode("ERR_SOCKET_ACCEPT");
    TCPSocket::quit();
  }

  logger->info("request from client accepted...");
  return client;
}

bool TCPSocket::receive (int client_) {
  char buffer[BUFFER_SIZE]; // @todo déplacer ça dans une classe server...

  int status = recv(client_, buffer, BUFFER_SIZE, 0);

  if (status < 0) {
    logger->messageFromCode("ERR_SOCKET_CANNOT_RECEIVE");
    return false;
  }

  if (status == 0) {
    logger->messageFromCode("ERR_SOCKET_CLIENT_DISCONNECTED");
    return false;
  }
  request = string(buffer); // @todo déplacer ça dans une classe server...

  logger->info("request from client catched...");
  return true;
}

TCPSocket& TCPSocket::deliver (int sock_, string message_) {
  // http://stackoverflow.com/questions/7352099/stdstring-to-char
  char * message = (char *) message_.c_str();
  ssize_t length = strlen(message);

  if (send(sock_, message, length, 0) < 0) {
    logger->messageFromCode("ERR_SOCKET_SEND");
    TCPSocket::quit();
  }
  logger->info("a response has been sent to the connected client...");
  return *this;
}

TCPSocket& TCPSocket::disconnect (int sock_) {
  if (sock_ > 0) {
    close(sock_);
  }

  logger->info("client disconnected...");
  return *this;
}

void TCPSocket::quit () {
  if (sock > 0) {
    close(sock);
  }

  logger->info("server closed...");
  exit(0);
}

// @todo refactor everything here [NO TIME =(]
string TCPSocket::getRessource () {

  string url, path, response;

  // Parsing URL
  size_t pos = 0;
  int n = 0;
  string delimiter = " ";

  while ( (pos = request.find(delimiter)) != string::npos) {
    if (n == 1) {
      url = request.substr(0, pos);
      break;
    }
    request.erase(0, pos + delimiter.length());
    n++;
  }

  // Find and return the ressource
  path = "./www" + url;

  if (url == "/") {
    path = "./www/index.html";
  }

  if (fileExists(path)) {
    response = "HTTP/1.1 200 OK\n";
    response = response + "Content-Type: text/html; charset=UTF-8\n";
    response = response + "\n\n";
    response = response + getFileContent(path);
  }
  else {
    response = "HTTP/1.1 404 OK\n";
    response = response + "Content-Type: text/html; charset=UTF-8\n";
    response = response + "Status: 404 File not found\n";
    response = response + "\n\n";
    response = response + getFileContent("./www/error404.html");
  }

  return response;
}


