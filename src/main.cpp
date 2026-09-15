#include "DocumentParser.h"

#include <iostream>
#include <string>
#include <vector>

int main() {
    DocumentParser parser;

    std::string text =
        "Hello, WORLD! This is a C++ Search Engine.";

    std::vector<std::string> tokens = parser.tokenize(text);

    std::cout << "Tokens:\n";

    for (const std::string& token : tokens) {
        std::cout << token << '\n';
    }

    return 0;
}
