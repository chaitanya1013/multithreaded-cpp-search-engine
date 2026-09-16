#ifndef TFIDF_H
#define TFIDF_H

#include <string>
#include <vector>

class TFIDF {
public:
    double termFrequency(
        const std::vector<std::string>& tokens,
        const std::string& term
    ) const;

    double inverseDocumentFrequency(
        int totalDocuments,
        int documentFrequency
    ) const;

    double calculate(
        double tf,
        double idf
    ) const;
};

#endif
