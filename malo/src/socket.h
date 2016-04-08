#ifndef SOCKET_H
#define SOCKET_H

  //#include "helpers/Logger.h"

  using namespace std;

  /**
   *
   * see:   http://www.linuxhowtos.org/manpages/2/socket.htm
   * usage: int domain/family, int type, int protocol
   */
  int createSocket(int family, int type, Logger *logger);

  /**
   *
   * see: http://www.linuxhowtos.org/manpages/2/bind.htm
   * int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
   */
  void bindSocket(int tsocket, int family, int port, Logger *logger);

  /**
   *
   *
   */
  void listenSocket(int tsocket, int port, Logger *logger);

  /**
   *
   * usage: accept (int sockfd, struct sockaddr *cli_addr, int *addrlen);
   */
  int acceptSocket(int tsocket, Logger *logger);

  /**
   *
   * usage: ssize_t read(int fd, void *buf, size_t count);
   */
  int readSocket(int request, void *message, int buffer, Logger *logger);

  /**
   *
   *
   */
  int writeSocket(void *message, int connection, int request, Logger *logger);

  /**
   *
   *
   */
  void closeSocket(int tsocket, int request, Logger *logger);

#endif
