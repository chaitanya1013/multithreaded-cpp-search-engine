#include "DocumentParser.h"

#include <cctype>
#include <sstream>

std::vector<std::string> DocumentParser::tokenize(
    const std::string& text
) const {
    std::vector<std::string> tokens;
    std::stringstream stream(text);
    std::string word;

    while (stream >> word) {
        std::string cleanedWord;

        for (char ch : word) {
            if (std::isalnum(static_cast<unsigned char>(ch))) {
                cleanedWord += static_cast<char>(
                    std::tolower(static_cast<unsigned char>(ch))
                );
            }
        }

        if (!cleanedWord.empty()) {
            tokens.push_back(cleanedWord);
        }
    }

    return tokens;
}
