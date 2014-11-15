#include "filesystem.hpp"

#include <fstream>
#include <sstream>

NOXIS_NS_BEGIN;

bool isFileExist(const std::string &path) {
    std::ifstream testFile(path);
    auto isOk = testFile.good();
    testFile.close();
    return isOk;
}

std::string joinPath(std::initializer_list<std::string> paths) {
    std::ostringstream result;
    auto i = paths.begin(), end = paths.end();

    if(i != end) {
        result << *i++;
    }

    while(i != end) {
        result << PATH_SEPARATOR << *i++;
    }

    return result.str();
}


NOXIS_NS_END;
