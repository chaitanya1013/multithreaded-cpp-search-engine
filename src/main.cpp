#include "DocumentParser.h"
#include "InvertedIndex.h"

#include <iostream>
#include <string>
#include <vector>

int main() {
    DocumentParser parser;
    InvertedIndex index;

    std::vector<std::string> documents = {
        "C++ is fast and powerful",
        "C++ is used for system programming",
        "Python is simple and powerful"
    };

    // Parse and index every document
    for (int i = 0; i < static_cast<int>(documents.size()); ++i) {
        std::vector<std::string> tokens =
            parser.tokenize(documents[i]);

        index.addDocument(i + 1, tokens);
    }

    // Search for a word
    std::string query = "c++";

    std::set<int> results = index.search(query);

    std::cout << "Search query: " << query << '\n';
    std::cout << "Documents found:\n";

    for (int documentId : results) {
        std::cout << "Document " << documentId << '\n';
    }

    return 0;
}
