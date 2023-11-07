#include "extractvalue.hh"
#include <sstream>
#include <cctype>

long long extractValue(const std::string &line) {
    std::istringstream iss(line);
    long long value = 0;
    while (iss >> std::skipws) {
        if (std::isdigit(iss.peek())) {
            iss >> value;
            break;
        } else {
            iss.ignore();
        }
    }
    return value;
}
