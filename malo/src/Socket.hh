#ifndef SOCKET_H
#define SOCKET_H

  using namespace std;

  #include "helpers/Logger.hh"

  /**
   * Class Socket
   */
  class Socket {

    private:

      /* Logger instance */
      Logger* logger;

    public:

      /**
       * Contructor
       */
      Socket (Logger* logger);

      /**
       * Destructor
       */
      virtual ~Socket ();

      /**
       *
       * see:   http://www.linuxhowtos.org/manpages/2/socket.htm
       * usage: int domain/family, int type, int protocol
       */
      int open(int family, int type, int port);

      /**
       *
       * see: http://www.linuxhowtos.org/manpages/2/bind.htm
       * int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
       */
      void bind(int tsocket, int family, int port);

      /**
       *
       *
       */
      void listen(int tsocket, int port);

      /**
       *
       * usage: accept (int sockfd, struct sockaddr *cli_addr, int *addrlen);
       */
      int accept(int tsocket);

      /**
       *
       * usage: ssize_t read(int fd, void *buf, size_t count);
       */
      int read(int request, void* message, int buffer);

      /**
       *
       *
       */
      int write(void *message, int connection, int request);

      /**
       *
       *
       */
      void close(int tsocket, int request);

  };

#endif
