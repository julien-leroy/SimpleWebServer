#ifndef LOGGER_H
#define LOGGER_H

  #include <string>

  using namespace std;

  /**
   * Class Logger
   */
  class Logger {

    protected:

      /**
       *
       */
      void print (string message);

    public:

      /**
       * Contructor
       */
      Logger ();

      /**
       * Destructor
       */
      virtual ~Logger ();

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

  };//void info(string) {}

#endif
