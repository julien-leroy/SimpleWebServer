#ifndef STREAM_SOCKET_H

  #define STREAM_SOCKET_H

  #include <sys/types.h>
  #include <sys/socket.h>
  #include <netinet/in.h>

  #include "../helpers/Logger.hh"

  /**
   * @class StreamSocket
   *
   * Creates a stream socket server that listen to network transmissions over a
   * specific interface: the loopback IP address (0) and a port (e.g.: 8888)
   * The Socket's instance is able to read and write data in this interface
   */
  class StreamSocket {

    private:
      /* Socket instance */
      int sock;
      /* Socket family (AF_INET, AF_INET6, etc.) */
      int protocol;
      /* Port on which the Socket's instance is binded and listening */
      int port;
      /* sockaddr_in structure declaration */
      struct sockaddr_in clientAddr, serverAddr;
      /* Logger instance */
      Logger* logger;

    public:
      /**
       * Contructor
       */
      StreamSocket (int protocol_, Logger* logger_);

      /**
       * Creates a new stream socket
       *
       * @see http://www.linuxhowtos.org/manpages/2/socket.htm
       */
      StreamSocket& create ();

      /**
       * Bind an address to a new socket
       *
       * @see http://www.linuxhowtos.org/manpages/2/bind.htm
       */
      StreamSocket& attach (int port_);

      /**
       * Listen for incoming connection requests on a socket (passive mode)
       *
       * @see http://www.linuxhowtos.org/manpages/2/listen.htm
       */
      StreamSocket& lookOut (int maximumPendingRequestsQueueSize_);

      /**
       * Accept a connection on a socket
       *
       * @see http://www.linuxhowtos.org/manpages/2/accept.htm
       */
      StreamSocket& acquire ();

      /**
       * Sends a message on a socket
       *
       * @see http://www.linuxhowtos.org/manpages/2/send.htm
       */
      StreamSocket& deliver (const void* buffer_, size_t length_, int flags_);
      // @todo refactor this shit using "string data"

      /**
       * Close a socket
       */
      void quit ();

  };

#endif
