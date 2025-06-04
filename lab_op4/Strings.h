#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> separateString(string source, char symb);
bool isDouble(const string source);
void sortStringVector(vector<vector<string>> source, int col = 0);
int findStringVectorMinValue(vector<vector<string>> source, int from, int col = 0);
void swapStringVectors(vector<string> *val1, vector<string> *val2);
float strval(string source, bool &status);
float strval(string source);
