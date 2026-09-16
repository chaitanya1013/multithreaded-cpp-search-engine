#include "DocumentParser.h"
#include "DocumentReader.h"
#include "DocumentStore.h"
#include "InvertedIndex.h"
#include "TFIDF.h"

#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include <vector>

int main() {
    DocumentReader reader;
    DocumentParser parser;
    DocumentStore store;
    InvertedIndex index;
    TFIDF tfidf;


    std::vector<std::string> filePaths = {
        "../data/doc1.txt",
        "../data/doc2.txt",
        "../data/doc3.txt"
    };

    for (int i = 0; i < static_cast<int>(filePaths.size()); ++i) {
        int documentID = i + 1;
	try {
            std::string text = reader.readFile(filePaths[i]);

            std::vector<std::string> tokens =
                parser.tokenize(text);

	    store.addDocument(documentID, filePaths[i], tokens);
            index.addDocument(documentID, tokens);

        } catch (const std::exception& error) {
            std::cerr << error.what() << '\n';
        }
    }

    std::string query = "python";
    std::set<int> results = index.search(query);

    std::cout << "Search query: " << query << '\n';
    
    int totalDocuments = store.getDocumentCount();
    int documentFrequency = static_cast<int>(results.size());

    double idf = tfidf.inverseDocumentFrequency(
        totalDocuments,
        documentFrequency
    );

    for (int documentId : results) {
        const std::vector<std::string>& tokens =
            store.getTokens(documentId);

        double tf = tfidf.termFrequency(tokens, query);

        double score = tfidf.calculate(tf, idf);

        std::cout
            << "Document ID: " << documentId
            << " | File: " << store.getFilePath(documentId)
            << " | TF: " << tf
            << " | IDF: " << idf
            << " | TF-IDF: " << score
            << '\n';
    }

    return 0;
}
