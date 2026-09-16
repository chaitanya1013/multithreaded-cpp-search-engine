#include "DocumentStore.h"

void DocumentStore::addDocument(
    int documentId,
    const std::string& filePath
) {
    documents[documentId] = filePath;
}

std::string DocumentStore::getFilePath(int documentId) const {
    auto it = documents.find(documentId);

    if (it != documents.end()) {
        return it->second;
    }

    return "";
}
