#include "DocumentParser.h"

#include <cctype>
#include <sstream>

namespace {

bool isTrimCharacter(char ch) {
    return !std::isalnum(static_cast<unsigned char>(ch)) &&
           ch != '+' &&
           ch != '#' &&
           ch != '.' &&
           ch != '-' &&
           ch != '_' &&
           ch != '\'';
}

} // namespace

std::vector<std::string> DocumentParser::tokenize(
    const std::string& text
) const {
    std::vector<std::string> tokens;
    std::stringstream stream(text);
    std::string word;

    while (stream >> word) {

        // Remove unwanted punctuation from the beginning
        while (!word.empty() && isTrimCharacter(word.front())) {
            word.erase(word.begin());
        }

        // Remove unwanted punctuation from the end
        while (!word.empty() && isTrimCharacter(word.back())) {
            word.pop_back();
        }

        if (word.empty()) {
            continue;
        }

        // Convert letters to lowercase
        // Meaningful symbols remain unchanged
        for (char& ch : word) {
            ch = static_cast<char>(
                std::tolower(static_cast<unsigned char>(ch))
            );
        }

        tokens.push_back(word);
    }

    return tokens;
}
