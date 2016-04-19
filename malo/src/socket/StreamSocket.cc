/* -*- C++ -*- */

/****************************************************************************
** Copyright (C) 2016-2018 Malo Blanchard
**
** This file is part of the SimpleWebServer project
**
** This file may be distributed under the terms of the SimpleWebServer
** license as defined by SimpleWebServer and appearing in the file
** LICENSE included in the packaging of this file.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
** See https://github.com/Izin/sws/master/LICENSE for licensing information.
**
** Contact github@maloblanchard.com if any conditions of this licensing are
** not clear to you.
**/

#include <sys/socket.h> // Core socket functions and data structures
#include <netinet/in.h> // AF_INET and AF_INET6 address families and their corresponding protocol families
#include <arpa/inet.h>  // Core socket functions and data structures (eg: inet_addr)
#include <netdb.h>      // Functions for translating protocol names and host names into numeric addresses
#include <unistd.h>     // close()
#include <string.h>     // strlen
#include <string>       // string

#include "StreamSocket.hh"

#define BUFFER_SIZE 100 // Max size for a message

using namespace std;

StreamSocket::StreamSocket (int protocol_, Logger* logger_) {
  sock     = -1;
  protocol = protocol_;
  port     = 0;
  logger   = logger_;
}

StreamSocket& StreamSocket::create () {
  if (sock > -1) {
    logger->messageFromCode("ERR_SOCKET_ALREADY_CREATED");
    return *this;
  }

  sock = socket(protocol, SOCK_STREAM, 0);

  if (sock < 0) {
    logger->messageFromCode("ERR_SOCKET_CREATE");
    exit(1);
  }

  logger->info("new socket created...");
  return *this;
}

StreamSocket& StreamSocket::attach (int port_) {
  port = port_;

  // https://www.mkssoftware.com/docs/man3/memset.3.asp
  memset(&server, 0, sizeof(server));

  server.sin_family      = protocol;
  server.sin_port        = htons(port); // host to network short
  server.sin_addr.s_addr = INADDR_ANY;  // Any Internet interface

  if (bind(sock, (struct sockaddr *) &server, sizeof(server)) < 0) {
    logger->messageFromCode("ERR_SOCKET_BIND");
    StreamSocket::quit();
  }

  logger->info("socket attached to '" + to_string(INADDR_ANY) + ":" + to_string(port) + "...");
  return *this;
}

StreamSocket& StreamSocket::lookOut (int maximumPendingRequestsQueueSize_) {

  if (listen(sock, maximumPendingRequestsQueueSize_) < 0) {
    logger->messageFromCode("ERR_SOCKET_LISTEN");
    StreamSocket::quit();
  }

  logger->info("socket waiting for client connections (queueSize: " + to_string(maximumPendingRequestsQueueSize_) + ")...");
  return *this;
}

int StreamSocket::acquire () {
  int size, request;
  socklen_t length = sizeof(client);

  memset(&client, 0, sizeof(client));

  size    = sizeof(struct sockaddr_in);
  request = accept(sock, (struct sockaddr*) &client, &length);

  if (request < 0) {
    logger->messageFromCode("ERR_SOCKET_ACCEPT");
    StreamSocket::quit();
  }

  logger->info("request from client accepted...");
  return request;
}

StreamSocket& StreamSocket::receive (int client_) {
  // http://stackoverflow.com/questions/7352099/stdstring-to-char
  char buffer[BUFFER_SIZE];
  int status;

  while (1) {

    status = recv(client_, buffer, BUFFER_SIZE, 0);

    if (status < 0) {
      logger->messageFromCode("ERR_SOCKET_CANNOT_RECEIVE");
      break;
    }

    if (status == 0) {
      logger->messageFromCode("ERR_SOCKET_CLIENT_DISCONNECTED");
      break;
    }

    if (status > 0) {
      logger->info("------------------------------");
      logger->info(buffer);
      logger->info("------------------------------");
    }

    if (strcmp(buffer, "exit") == 0) {
      break;
    }

  }

  return *this;
}

StreamSocket& StreamSocket::deliver (string message_) {
  // http://stackoverflow.com/questions/7352099/stdstring-to-char
  char * message = (char *) message_.c_str();
  ssize_t length = strlen(message);
  logger->info(logger->toString(sock) + " -> " + message_ + "(" + logger->toString(length) + ")");

  if (send(sock, message, length, 0) < 0) {
    logger->messageFromCode("ERR_SOCKET_SEND");
    StreamSocket::quit();
  }
  logger->info("send ok");

  logger->info("a message has been sent on this socket...");
  return *this;
}

StreamSocket& StreamSocket::disconnect (int sock_) {
  if (sock_ > 0) {
    close(sock_);
  }

  logger->info("client disconnected...");
  return *this;
}

void StreamSocket::quit () {
  if (sock > 0) {
    close(sock);
  }

  logger->info("server closed...");
}



