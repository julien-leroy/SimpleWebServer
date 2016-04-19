#include <map>

class Request {
  public:
    std::string method;
    std::string path;
    std::string params;
    map<string, string> headers;
    map<string, string> query;
    map<string, string> cookies;
    Request() {}
};
