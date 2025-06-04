#pragma once

#include <iostream>
#include <vector>

using std::vector;
using std::string;

int loadHeadersFromFile(vector<string> *headers, const string fileName);
int loadDataFromFile(vector<vector<string>> &data, const string fileName);
