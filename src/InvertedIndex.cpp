#include "InvertedIndex.h"

void InvertedIndex::addDocument(
    int documentId,
    const std::vector<std::string>& tokens
) {
    for (const std::string& token : tokens) {
        index[token].insert(documentId);
    }
}

std::set<int> InvertedIndex::search(
    const std::string& token
) const {
    auto it = index.find(token);

    if (it != index.end()) {
        return it->second;
    }

    return {};
}
