#ifndef INTERNETSOCKET_H
#define INTERNETSOCKET_H

  #include <sys/types.h>
  #include <sys/socket.h>
  #include <netinet/in.h>

  #include "../helpers/Logger.hh"

  /**
   * Class InternetSocket
   */
  class InternetSocket {

    private:

      /* Logger instance */
      Logger* logger; // @todo voir pour mettre logger en static ?

      /* Socket family|protocol (AF_INET for IPV4, or AF_INET6 for IPV6)
       * http://www.linuxhowtos.org/manpages/2/socket.htm
       */
      int protocol;

      /* Internet Socket type (stream, datagram, raw, rdm, etc.)
       * http://www.linuxhowtos.org/manpages/2/socket.htm
       */
      int type;

      /* Port on which the Internet Socket's instance is binded and listening */
      int port;

      /* Internet Socket instance */
      int InternetSocketInstance;

      /* Internet Socket address */
      // see: http://www.cas.mcmaster.ca/~qiao/courses/cs3mh3/tutorials/socket.html
      // struct sockaddr_in {
      //   short           sin_family;  /* AF_INET */
      //   u_short         sin_port;    /* 16-bit port number */
      //   struct in_addr  sin_addr;
      //   char            sin_zero[8]; /* unused */
      // };
      struct sockaddr_in client, server;

    public:

      /**
       * Contructor
       */
      InternetSocket (int protocol, int type, int port, Logger* logger);

      /**
       *
       * see:   http://www.linuxhowtos.org/manpages/2/socket.htm
       * usage: int domain/family, int type, int protocol
       */
      void open ();

      /**
       * Bind a name to a socket
       * see: http://www.linuxhowtos.org/manpages/2/bind.htm
       * int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
       */
      void bindName ();

      /**
       * Get ready for accepting connection requests from a client
       */
      void listenToClient (int maxRequestsToQueue);

      /**
       * Set up an actual connection with a client process
       * usage: accept (int sockfd, struct sockaddr *cli_addr, int *addrlen);
       */
      int acceptConnection ();

      /**
       *
       * usage: ssize_t read(int fd, void *buf, size_t count);
       */
      int read (int request, void* message, int buffer);

      /**
       *
       *
       */
      int write (void *message, int connection, int request);

      /**
       *
       *
       */
      void close (int request);

  };

#endif
