#ifndef SOCKET_H
#define SOCKET_H

  #include <sys/types.h>
  #include <sys/socket.h>

  #include "helpers/Logger.hh"

  /**
   * Class Socket
   */
  class Socket {

    private:

      /* Logger instance */
      Logger* logger; // @todo voir pour mettre logger en static ?

      /* Socket family (IPV4, IPV6, unix, ax25, etc.)
       * http://www.linuxhowtos.org/manpages/2/socket.htm
       */
      int family;

      /* Socket type (stream, datagram, raw, rdm, etc.)
       * http://www.linuxhowtos.org/manpages/2/socket.htm
       */
      int type;

      /* Port on which the Socket's instance is binded and listening */
      int port;

      /* Socket instance */
      int socket;

      // @todo BULLSHIT
      int servlen;
        socklen_t clilen;
      // see: http://www.cas.mcmaster.ca/~qiao/courses/cs3mh3/tutorials/socket.html
      // struct sockaddr_in {
      //   short           sin_family;  /* AF_INET */
      //   u_short         sin_port;    /* 16-bit port number */
      //   struct in_addr  sin_addr;
      //   char            sin_zero[8]; /* unused */
      // };
      //struct sockaddr_in cli_addr, serv_addr; // /!\ ATTENTION !! à@revoirDépendance !

    public:

      /**
       * Contructor
       */
      Socket (int family, int type, int port, Logger* logger);

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
      void bind ();

      /**
       *
       *
       */
      void listen ();

      /**
       *
       * usage: accept (int sockfd, struct sockaddr *cli_addr, int *addrlen);
       */
      int accept ();

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
