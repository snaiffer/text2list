#include "WordAggregator.h"

string WordAggregator::GetWord() {
    if (m_word_isBuilt) {
        string temp = m_word;
        m_word.clear();
        m_word_isBuilt = false;
        return temp;
    }
    return "";
}

string& operator<< (string &str, WordAggregator &aggregator) {
    str = aggregator.m_word;
    return str;
}


istream& operator>> (istream &in, WordAggregator &aggregator) {
    in >> aggregator.m_symbol;
    aggregator.aggregate();
    return in;
}

void WordAggregator::aggregate() {
    if ( m_symbol == ' ' || m_symbol == '\t' || m_symbol == '\n' || (m_separators.find(m_symbol) != -1) ) {
        if ( !m_word.empty() )
            m_word_isBuilt = true;
        return;
    }
    else {
        if ( m_word_isBuilt )
            GetWord();
        m_word += m_symbol;
    }

    return;
}

