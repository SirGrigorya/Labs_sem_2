#ifndef VECTOROPERATIONS_H
#define VECTOROPERATIONS_H

#include <vector>
#include <string>

using namespace std;

bool doubleVectorComp(vector<double> val1, vector<double> val2);
void recalcRepeatsInDoubleVector(vector<vector<double>> &source);

int findDoubleVectorsMinIndex(vector<vector<double>> &source, int col = 0);
double findDoubleVectorsMinValue(vector<vector<double>> &source, int col = 0);
int findDoubleVectorsMaxIndex(vector<vector<double>> &source, int col = 0);
double findDoubleVectorsMaxValue(vector<vector<double>> &source, int col = 0);

int findDoubleVectorMinIndex(vector<double> &source, int start = 0);
double findDoubleVectorMinValue(vector<double> &source);
int findDoubleVectorMaxIndex(vector<double> &source);
double findDoubleVectorMaxValue(vector<double> &source);

void sortDoubleVector(vector<double> &source);
double findDoubleVectorMedianValue(vector<double> &source);

double calcDoubleVectorsMiddleValue(vector<vector<double>> &source, int col = 0);
int getDoubleVectorsNearestElement(vector<vector<double>> &source, double value, int col = 0);

double calcDoubleVectorSum(vector<double> &source);
double calcDoubleVectorMiddleValue(vector<double> &source);

vector<float> convertVectorFromStringToDouble(vector<string> &data);
vector<vector<float>> convertVectorsFromStringToDouble(vector<vector<string>> &data);

int getVectorMinIndex(vector<float> &data);
int getVectorMaxIndex(vector<float> &data);

float getVectorMinValue(vector<float> &data);
float getVectorMaxValue(vector<float> &data);

void getVectorsMinIndexes(vector<vector<float>> &data, int &x, int &y);
void getVectorsMaxIndexes(vector<vector<float>> &data, int &x, int &y);

float getVectorsMinValue(vector<vector<float>> &data);
float getVectorsMaxValue(vector<vector<float>> &data);

void normalizeVector(vector<float> &data, float minRange, float maxRange, float minValue, float maxValue);
void normalizeVectors(vector<vector<float>> &data, float minRange, float maxRange);
#endif // VECTOROPERATIONS_H
