#ifndef SERVER_H

  #include <string>
  #include <map>

  #include "../helpers/Logger.hh"
  #include "./Request.hh"
  #include "./Response.hh"

  #define SERVER_H

  /**
   * @todo commenter
   */
  class Server {
    public:
      bool start(int port_);
      void get(std::string_, void (*callback)(Request*, Response*));
      void post(std::string_, void (*callback)(Request*, Response*));
      void stop();
    private:
      void parseHeader(char*, Request*, Response*);
      bool matchRoute(Request*, Response*);
      void listDirectories(Request* req, Response* res);
      std::string getMimeType(Request* req);
  };

#endif
