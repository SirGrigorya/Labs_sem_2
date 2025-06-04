#include "StringsManager.h"
#include <sstream>

using namespace std;

vector<string> StringManager::separateString(string str, char separator)
{
    stringstream sstream(str);
    vector<string> fields;
    string word;

    while(getline(sstream, word, separator))
        fields.push_back(word);

    return fields;
}
