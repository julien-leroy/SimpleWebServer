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
      /* Socket protocol family (AF_INET, AF_INET6, etc.) */
      int protocol;
      /* Port on which the Socket's instance is binded and listening */
      int port;
      /* sockaddr_in structure declaration */
      struct sockaddr_in client, server;
      /* Logger instance */
      Logger* logger;

    public:
      /**
       * Contructor
       *
       * @param  protocol_  Protocol family's ID for socket library
       * @param  logger_    Pointer for the Logger instance
       */
      StreamSocket (int protocol_, Logger* logger_);

      /**
       * Creates a new stream socket
       * @see {@link http://www.linuxhowtos.org/manpages/2/socket.htm}
       *
       * @return  Address of the SreamSocket instance
       */
      StreamSocket& create ();

      /**
       * Bind an address to a new socket
       * @see {@link http://www.linuxhowtos.org/manpages/2/bind.htm}
       *
       * @param  port_  Port number
       * @return Address of the SreamSocket instance
       */
      StreamSocket& attach (int port_);

      /**
       * Listen for incoming connection requests on a socket (passive mode)
       * @see {@link http://www.linuxhowtos.org/manpages/2/listen.htm}
       *
       * @param maximumPendingRequestsQueueSize_ Maximum size of queue for requests
       * @return Address of the SreamSocket instance

       */
      StreamSocket& lookOut (int maximumPendingRequestsQueueSize_);

      /**
       * Accept a connection on a socket
       * @see {@link http://www.linuxhowtos.org/manpages/2/accept.htm}
       *
       * @return Result of the traitement of the client request
       */
      int acquire ();

      /**
       * Sends a message on a socket
       * @see {@link http://www.linuxhowtos.org/manpages/2/send.htm}
       *
       * @param  client_ Client socket value
       * @return Status of the client request
       */
      bool receive (int client_);

      /**
       * Sends a message on a socket
       * @see {@link http://www.linuxhowtos.org/manpages/2/send.htm}
       *
       * @param  sock_    Client socket value
       * @param  message_ Port number
       * @return Address of the SreamSocket instance
       */
      StreamSocket& deliver (int sock_, std::string message_);

      // @todo ajouter les méthodes liées au client comme 'connect'
      // @see http://www.binarytides.com/code-a-simple-socket-client-class-in-c/

      /**
       * Disconnect the current Socket instance
       *
       * @param  sock_ Client socket value
       * @return Address of the SreamSocket instance
       */
      StreamSocket& disconnect (int sock_);

      /**
       * Close the server Socket instance
       */
      void quit ();

  };

#endif
