#include <fstream>
#include <sstream>

class Response {
  public:
    int code;
    string phrase;
    string type;
    string date;
    stringstream body;
    Response() {
        code = 200;
        phrase = "OK";
        type = "text/html";
        body << "";

        // set current date and time for "Date: " header
        char buffer[100];
        time_t now = time(0);
        struct tm tstruct = *gmtime(&now);
        strftime(buffer, sizeof(buffer), "%a, %d %b %Y %H:%M:%S %Z", &tstruct);
        date = buffer;
    }

    void send(string str) {
       body << str;
    };
    void send(const char* str) {
       body << str;
    };
  private:
};
