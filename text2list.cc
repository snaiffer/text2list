#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "./lib/WordAggregator.h"
#include "./lib/Exceptions.h"

#define IN_FILE     "text.txt"
#define OUT_FILE    "result.txt"
#define SEPAR_FILE  "./etc/separators.conf"
#define EXCEP_FILE  "./etc/exceptions.conf"

using namespace std;

int main() {

    ifstream f_text(IN_FILE);
    if ( !f_text ) {
        cerr << "Can't open input file: " << IN_FILE << endl;
        exit(1);
    }
    f_text >> noskipws;

    ofstream f_result(OUT_FILE);
    if ( !f_result ) {
        cerr << "Can't open output file: " << OUT_FILE << endl;
        exit(1);
    }


    WordAggregator aggregator;

    ifstream f_separ(SEPAR_FILE);
    if ( !f_separ ) {
        cerr << "Can't open separator's file: " << SEPAR_FILE << endl;
        exit(1);
    }

    string separ; f_separ >> separ; aggregator.SetSeparators(separ);

    Exceptions exceptions(EXCEP_FILE);

    while (f_text) {
        f_text >> aggregator;
        if ( aggregator.word_isBuilt() ) {
            string CurWord = aggregator.GetWord();
            if ( !exceptions.find(CurWord) )
                f_result << CurWord << endl;
        }
    }

    return 0;
}
