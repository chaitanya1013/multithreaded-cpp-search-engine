#include "TFIDF.h"

#include <cmath>

double TFIDF::termFrequency(
    const std::vector<std::string>& tokens,
    const std::string& term
) const {
    if (tokens.empty()) {
        return 0.0;
    }

    int count = 0;

    for (const std::string& token : tokens) {
        if (token == term) {
            ++count;
        }
    }

    return static_cast<double>(count) /
           static_cast<double>(tokens.size());
}

double TFIDF::inverseDocumentFrequency(
    int totalDocuments,
    int documentFrequency
) const {
    if (totalDocuments <= 0 || documentFrequency <= 0) {
        return 0.0;
    }

    return std::log(
        static_cast<double>(totalDocuments) /
        static_cast<double>(documentFrequency)
    );
}

double TFIDF::calculate(
    double tf,
    double idf
) const {
    return tf * idf;
}
