#ifndef LOGGER_H
#define LOGGER_H

  #include <string>

  /**
   * Class Logger
   */
  class Logger {

    protected:

      /**
       *
       */
      void console (std::string message);

    public:

      /**
       * Contructor
       */
      Logger ();

      /**
       *
       */
      void info (std::string message);

      /**
       *
       */
      void error (std::string code);

      /**
       *
       */
      void debug (std::string message);


      /**
       *
       */
      std::string toString (int text);

  };//void info(string) {}

#endif
