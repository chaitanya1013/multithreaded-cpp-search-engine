#include "DocumentStore.h"

void DocumentStore::addDocument(
    int documentId,
    const std::string& filePath,
    const std::vector<std::string>& tokens
) {
    documents[documentId] = filePath;
    documentTokens[documentId] = tokens;
}

std::string DocumentStore::getFilePath(int documentId) const {
    auto it = documents.find(documentId);

    if (it != documents.end()) {
        return it->second;
    }

    return "";
}

const std::vector<std::string>& DocumentStore::getTokens(
    int documentId
) const {
    static const std::vector<std::string> emptyTokens;

    auto it = documentTokens.find(documentId);

    if (it != documentTokens.end()) {
        return it->second;
    }

    return emptyTokens;
}

int DocumentStore::getDocumentCount() const {
    return static_cast<int>(documents.size());
}
