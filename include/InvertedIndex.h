#ifndef INVERTED_INDEX_H
#define INVERTED_INDEX_H

#include <string>
#include <unordered_map>
#include <set>
#include <vector>

class InvertedIndex {
public:
    void addDocument(
        int documentId,
        const std::vector<std::string>& tokens
    );

    std::set<int> search(const std::string& token) const;

private:
    std::unordered_map<std::string, std::set<int>> index;
};

#endif
