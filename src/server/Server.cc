#include <string>
#include <map>

#include "Server.hh"

#define SERVER_NAME "Simple Web Server"
#define SERVER_VERSION "0.1.0"


bool Server::start(int port_) {
  return true;
}

void Server::get(std::string_, void (*callback)(Request*, Response*)) {

}

void Server::post(std::string_, void (*callback)(Request*, Response*)) {

}

void Server::stop() {

}

void listDirectories(Request* req, Response* res) {
  unsigned char isFile = 0x8, isFolder = 0x4;
  struct dirent *dir;
  int status;
  struct stat st_buf;
  char* actual_path;
  char* base_path = realpath(req->params.c_str(), NULL);
  string new_path = "";
  actual_path = realpath(req->params.c_str(), NULL);

  // ??
  if (req->query.find("open") != req->query.end()) {
    new_path += req->query["open"];
    strcat(actual_path, new_path.c_str());
  }

  //

}

string getMimeType(Request* req) {
  map<string, string> mime;

  // https://github.com/konteck/wpp/blob/master/web%2B%2B.hpp
  mime["jpg"] = "image/jpeg";
  mime["jpeg"] = "image/jpeg";
  mime["jpe"] = "image/jpeg";
  mime["html"] = "text/html";
  mime["txt"] = "text/plain";
  mime["dir"] = "application/x-director";

}
