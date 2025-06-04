#include "Files.h"

#include <fstream>
#include "Strings.h"

using namespace std;


bool isNumber(const string& s)
{
    if (s.empty()) return false;

    char* end = nullptr;
    strtod(s.c_str(), &end);
    return (*end == '\0');
}

int loadDataFromFile(vector<vector<string>> &data, const string fileName)
{
    fstream file(fileName);
    if (!file)
        return 1;

    string row = "";
    unsigned int cols = 0;
    bool nonNumericFound = false;

    while (getline(file, row))
    {
        vector<string> fields = separateString(row, ',');

        if (!cols)
            cols = fields.size();

        while (fields.size() < cols)
            fields.push_back("");

        for (const string& field : fields)
        {
            if (!isNumber(field))
                nonNumericFound = true;
        }

        data.push_back(fields);
    }

    file.close();

    return nonNumericFound ? 1 : 0;
}
