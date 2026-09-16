#ifndef DOCUMENT_STORE_H
#define DOCUMENT_STORE_H

#include <string>
#include <unordered_map>

class DocumentStore {
public:
    void addDocument(int documentId, const std::string& filePath);

    std::string getFilePath(int documentId) const;

private:
    std::unordered_map<int, std::string> documents;
};

#endif
