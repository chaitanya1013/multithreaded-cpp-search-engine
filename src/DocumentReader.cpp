#include "DocumentReader.h"

#include <fstream>
#include <sstream>
#include <stdexcept>

std::string DocumentReader::readFile(
    const std::string& filePath
) const {
    std::ifstream file(filePath);

    if (!file.is_open()) {
        throw std::runtime_error(
            "Unable to open file: " + filePath
        );
    }

    std::stringstream buffer;
    buffer << file.rdbuf();

    return buffer.str();
}
