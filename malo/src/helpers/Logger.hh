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
      void console (std::string message_);

    public:

      /**
       * Contructor
       */
      Logger ();

      /**
       *
       */
      void info (std::string message_);

      /**
       *
       */
      void error (std::string code_);

      /**
       *
       */
      void debug (std::string message_);

      /**
       *
       */
      void messageFromCode (std::string code_);

      /**
       *
       */
      std::string toString (int text_);

  };

#endif
