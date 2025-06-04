#include "Strings.h"

vector<string> separateString(const string source, char symb)
{
    vector<string> parts;
    stringstream line(source);

    string word = "";
    while(getline(line, word, symb))
        parts.push_back(word);
    return parts;
}

bool isDouble(const string source)
{
    bool status = true;
    int length = source.length();
    for(int i = 0; i < length && status; i++)
    {
        if(!(('0' <= source[i] && source[i] <= '9') || source[i] == '.' || source[i] == '-'))
            status = false;
    }
    return status;
}

void sortStringVector(vector<vector<string>> source, int col)
{
    int size = source.size();
    for(int i = 0; i < size; i++)
        swapStringVectors(&source[i], &source[findStringVectorMinValue(source, i, col)]);
}

int findStringVectorMinValue(vector<vector<string>> source, int from, int col)
{
    int size = source.size();
    int min = from;
    for(int i = from + 1; i < size; i++)
    {
        if(source[i][col].compare(source[min][col]) < 0)
            min = i;
    }
    return min;
}

void swapStringVectors(vector<string> *val1, vector<string> *val2)
{
    vector<string> temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}

float strval(string source, bool &status)
{
    float value;
    if(!isDouble(source))
    {
        value = 0.0;
        status = false;
    }
    else
    {
        value = stof(source);
        status = true;
    }

    return value;
}

float strval(string source)
{
    bool temp;
    float value = strval(source, temp);

    return value;
}
