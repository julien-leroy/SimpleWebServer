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

#include <iostream> // std::cout
#include <cstring>  // std::string, std::to_string

#include "helpers/Logger.hh"
#include "socket/StreamSocket.hh"

int main(int argc, char *argv[]) {

  size_t length = 255;
  int client;

  /* Logger instance */
  Logger *logger = new Logger();

  /* StreamSocket instance */
  StreamSocket socket = StreamSocket(AF_INET, logger);

  socket.create()
        .attach(8888)
        .lookOut(5);

  while (1) {
    client = socket.acquire();
    if (socket.receive(client)) {
      socket.deliver(client, "coucou client !")
            .disconnect(client);
    }
  }

  socket.quit();

  return 0;
}
