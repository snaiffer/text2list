#include "Exceptions.h"

Exceptions::Exceptions(string FileName) {
    ReadFromFile(FileName);
}


void Exceptions::ReadFromFile(string &FileName) {
    ifstream f_excep(FileName.c_str());
    if ( !f_excep ) {
//        cerr << "Can't open exception file: " << f_excep << endl;
        dict.clear();
        return;
    }

    while ( f_excep ) {
        string CurWord;
        f_excep >> CurWord;
        dict.push_back(CurWord);
    }

}

bool Exceptions::find(string &target) {
    vector<string>::iterator it;

    for (it=dict.begin(); it<dict.end(); it++)
        if ( *it == target )
            return true;
    return false;
}
