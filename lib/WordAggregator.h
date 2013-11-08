#ifndef WORDAGGREGATOR_H
#define WORDAGGREGATOR_H

#include <string>
#include <fstream>

using namespace std;

class WordAggregator {
    char m_symbol;
    string m_word;
    bool m_word_isBuilt;
    string m_separators;

    void aggregate();

  public:
    WordAggregator() : m_symbol(' '), m_word(""), m_word_isBuilt(false), m_separators("") { }

    bool word_isBuilt() const { return m_word_isBuilt; }

    string GetWord();

    void SetSeparators(string separators) { m_separators = separators; }

    friend string& operator<< (string &str, WordAggregator &aggregator);

    friend istream& operator>> (istream &in, WordAggregator &aggregator);

};


#endif
