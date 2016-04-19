/* -*- C++ -*- */

/****************************************************************************
** Copyright (C) 2016-2018 Malo Blanchard
**
** This file is part of the SimpleWebServer project
**
** This file may be distributed under the terms of the SimpleWebServer
** license as defined by SimpleWebServer and appearing in the file
** LICENSE included in the packaging of this file.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
** See https://github.com/Izin/sws/master/LICENSE for licensing information.
**
** Contact github@maloblanchard.com if any conditions of this licensing are
** not clear to you.
**/

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
