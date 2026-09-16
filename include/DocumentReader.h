#ifndef DOCUMENT_READER_H
#define DOCUMENT_READER_H

#include <string>

class DocumentReader {
public:
    std::string readFile(const std::string& filePath) const;
};

#endif
