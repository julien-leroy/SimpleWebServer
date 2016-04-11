#ifndef LOGGER_H
#define LOGGER_H

  #include <string>   // std::string, std::to_string

  using namespace std;

  /**
   * Class Logger
   */
  class Logger {

    protected:

      /**
       *
       */
      void console (string message);

    public:

      /**
       * Contructor
       */
      Logger ();

      /**
       *
       */
      void info (string message);

      /**
       *
       */
      void error (string code);

      /**
       *
       */
      void debug (string message);


      /**
       *
       */
      string toString (int text);

  };//void info(string) {}

#endif
