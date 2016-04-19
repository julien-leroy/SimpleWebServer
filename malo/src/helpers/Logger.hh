#ifndef LOGGER_H

  #define LOGGER_H

  #include <string>

  /**
   * Class Logger
   */
  class Logger {

    protected:

      /**
       * Display a message in the terminal
       *
       * @param message_  Content to display
       */
      void console (std::string message_);

    public:

      /**
       * Contructor
       */
      Logger ();

      /**
       * Send information to an input (stdout)
       *
       * @param message_  Content to display
       */
      void info (std::string message_);

      /**
       * Send error information to an input (stdout)
       *
       * @param code_  Content to display
       */
      void error (std::string code_);

      /**
       * Send debug information to an input (stdout)
       *
       * @param message_  Content to display
       */
      void debug (std::string message_);

      /**
       * Translates a code into an string, and then send it to an input (stdout)
       *
       * @param code_  Code to translate info a string
       */
      void messageFromCode (std::string code_);

      /**
       * Transform an integer value into a string value
       *
       * @param  n_ Integer value
       * @return String representing the transtyped integer
       */
      std::string toString (int n_);

  };

#endif
