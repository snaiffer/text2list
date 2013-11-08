#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Exceptions {
    vector<string> dict;

    void ReadFromFile(string &FileName);

  public:
    Exceptions(string FileName);

    bool find(string &target);

};


#endif

