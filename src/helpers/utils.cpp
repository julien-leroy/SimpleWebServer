#include <sys/stat.h>
#include <fstream>
#include <string>

/**
 * Check if a file exists
 *
 * @param  filename_  Name and path of the file to check
 * @return true if the file exists, else false
*/
bool fileExists(const std::string& filename_) {
  struct stat buf;
  return stat(filename_.c_str(), &buf) != -1;
}

/**
 *
 */
std::string getFileContent(const std::string& filename_) {
  std::string lines;
  std::ifstream in(filename_);

  if (in.is_open()) {
    std::string line;

    while (std::getline(in, line)) {
      lines = lines + line + "\n";
    }
  }

  return lines;
}
