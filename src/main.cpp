#include "DocumentParser.h"
#include "DocumentReader.h"
#include "InvertedIndex.h"

#include <iostream>
#include <set>
#include <string>
#include <vector>

int main() {
    DocumentReader reader;
    DocumentParser parser;
    InvertedIndex index;

    std::vector<std::string> filePaths = {
        "../data/doc1.txt",
        "../data/doc2.txt",
        "../data/doc3.txt"
    };

    for (int i = 0; i < static_cast<int>(filePaths.size()); ++i) {
        try {
            std::string text = reader.readFile(filePaths[i]);

            std::vector<std::string> tokens =
                parser.tokenize(text);

            index.addDocument(i + 1, tokens);

        } catch (const std::exception& error) {
            std::cerr << error.what() << '\n';
        }
    }

    std::string query = "python";

    std::set<int> results = index.search(query);

    std::cout << "Search query: " << query << '\n';
    std::cout << "Documents found:\n";

    for (int documentId : results) {
        std::cout << "Document " << documentId << '\n';
    }

    return 0;
}
