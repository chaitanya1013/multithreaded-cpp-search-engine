#ifndef DOCUMENT_STORE_H
#define DOCUMENT_STORE_H

#include <string>
#include <unordered_map>
#include <vector>


class DocumentStore {
public:
    void addDocument(int documentId, const std::string& filePath, const std::vector<std::string>& tokens);

    std::string getFilePath(int documentId) const;
	
    const std::vector<std::string>& getTokens(int documentId) const;

    int getDocumentCount() const;

private:
    std::unordered_map<int, std::string> documents;

    std::unordered_map<
        int,
        std::vector<std::string>
    > documentTokens;

};

#endif
