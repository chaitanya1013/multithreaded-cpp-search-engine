#ifndef DOCUMENT_PARSER_H
#define DOCUMENT_PARSER_H

#include <string>
#include <vector>

class DocumentParser {
public:
    std::vector<std::string> tokenize(const std::string& text) const;
};

#endif
