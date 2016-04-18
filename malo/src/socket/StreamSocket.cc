/* -*- C++ -*- */

/****************************************************************************
** Copyright (c) 2016 - 2018, Malo Blanchard
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

  int AddrSize = sizeof(serverAddr);

  // https://www.mkssoftware.com/docs/man3/memset.3.asp
  memset((char *) &serverAddr, AddrSize, 0);

  serverAddr.sin_family      = protocol;
  serverAddr.sin_port        = htons(port); // host to network short
  serverAddr.sin_addr.s_addr = INADDR_ANY;  // Any Internet interface

  int status = bind(sock, (struct sockaddr *) &serverAddr, AddrSize);

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
  return *this;
}

 int StreamSocket::acquire () {
  logger->info(logger->toString(sock));
  int size, request;

  size    = sizeof(struct sockaddr_in);
  request = accept(sock, (struct sockaddr *) &clientAddr, (socklen_t*) &size);

  if (request < 0) {
    logger->messageFromCode("ERR_SOCKET_ACCEPT");
    StreamSocket::quit();
  }

  logger->info("request from client accepted...");
  return request;
}

StreamSocket& StreamSocket::deliver (string message_) {
  // http://stackoverflow.com/questions/7352099/stdstring-to-char
  char * message = (char *) message_.c_str();
  ssize_t length, status;

  length  = strlen(message);
  logger->info(logger->toString(sock) + " -> " + message_ + "(" + logger->toString(length) + ")");

  status = send(sock, message, length, 0);

  logger->info("send ok");

  if (status < 0) {
    logger->messageFromCode("ERR_SOCKET_SEND");
    StreamSocket::quit();
  }

  logger->info("a message has been sent on this socket...");
  return *this;
}

void StreamSocket::quit () {
  if (sock > 0) {
    close(sock);
    sock = -1;
  }

  logger->info("socket closed...");
  exit(1);
}



