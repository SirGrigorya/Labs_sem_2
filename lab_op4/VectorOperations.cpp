#include "VectorOperations.h"
#include "Strings.h"
#include "Normalize.h"

bool doubleVectorComp(vector<double> val1, vector<double> val2)
{
    return val1[0] > val2[0];
}

void recalcRepeatsInDoubleVector(vector<vector<double>> &source)
{
    for(unsigned int i = 0; i < source.size(); i++)
    {
        double sum = source[i][1];
        int amount = 1;
        for(unsigned int j = i + 1; j < source.size(); j++)
        {
            if(source[i][0] == source[j][0])
            {
                sum += source[j][1];
                amount++;
                source.erase(source.begin() + j);
                j--;
            }
        }
        source[i].at(1) = sum / amount;
    }
}

int findDoubleVectorsMinIndex(vector<vector<double>> &source, int col)
{
    int size = source.size();
    int min = 0;
    for(int i = 1; i < size; i++)
        if(source[i][col] < source[min][col])
            min = i;

    return min;
}

int findDoubleVectorsMaxIndex(vector<vector<double>> &source, int col)
{
    int size = source.size();
    int max = 0;
    for(int i = 1; i < size; i++)
        if(source[i][col] > source[max][col])
            max = i;

    return max;
}

double calcDoubleVectorsMiddleValue(vector<vector<double>> &source, int col)
{
    double sum = 0.0;
    int size = source.size();
    for(int i = 0; i < size; i++)
        sum += source[i][col];

    double middle;

    if(!size)
        middle = 0.0;
    else
        middle = sum / size;
    return middle;
}

int getDoubleVectorsNearestElement(vector<vector<double>> &source, double value, int col)
{
    int size = source.size();
    int index = 0;
    for(int i = 1; i < size; i++)
    {
        if(abs(value - source[i][col]) < abs(value - source[index][col]))
            index = i;
    }
    return index;
}

double findDoubleVectorsMinValue(vector<vector<double>> &source, int col)
{
    return source[col][findDoubleVectorsMinIndex(source, col)];
}

double findDoubleVectorsMaxValue(vector<vector<double>> &source, int col)
{
    return source[col][findDoubleVectorsMaxIndex(source, col)];
}

int findDoubleVectorMinIndex(vector<double> &source, int start)
{
    int size = source.size();
    int min = start;
    for(int i = start + 1; i < size; i++)
        if(source[i] < source[min])
            min = i;

    return min;
}

int findDoubleVectorMaxIndex(vector<double> &source)
{
    int size = source.size();
    int max = 0;
    for(int i = 1; i < size; i++)
        if(source[i] > source[max])
            max = i;

    return max;
}

double findDoubleVectorMinValue(vector<double> &source)
{
    return source[findDoubleVectorMinIndex(source)];
}

double findDoubleVectorMaxValue(vector<double> &source)
{
    return source[findDoubleVectorMaxIndex(source)];
}

void sortDoubleVector(vector<double> &source)
{
    int size = source.size();
    for(int i = 0; i < size; i++)
        swap(source[i], source[findDoubleVectorMinIndex(source, i)]);
}


double findDoubleVectorMedianValue(vector<double> &source)
{
    vector<double> temp = source;
    sortDoubleVector(source);

    double value;

    int size = source.size();
    if(size % 2)
        value = (source[size / 2] + source[size / 2 + 1])/2;
    else
        value = source[size / 2];

    return value;
}

double calcDoubleVectorSum(vector<double> &source)
{
    double sum = 0.0;
    int size = source.size();
    for(int i = 0; i < size; i++)
        sum += source[i];
    return sum;
}

double calcDoubleVectorMiddleValue(vector <double> &source)
{
    double value;
    int amount = source.size();
    if(!amount)
        value = 0.0;
    else
        value = calcDoubleVectorSum(source) / amount;

    return value;
}

vector<float> convertVectorFromStringToDouble(vector<string> &data)
{
    vector<float> result;
    int size = data.size();
    for(int i = 0; i < size; i++)
        result.push_back(strval(data[i]));

    return result;
}
vector<vector<float>> convertVectorsFromStringToDouble(vector<vector<string>> &data)
{
    vector<vector<float>> result;
    int size = data.size();
    for(int i = 0; i < size; i++)
        result.push_back(convertVectorFromStringToDouble(data[i]));

    return result;
}

int getVectorMinIndex(vector<float> &data)
{
    int result = 0;
    int size = data.size();
    for(int i = 1; i < size; i++)
        if(data[i] < data[result])
            result = i;

    return result;
}

int getVectorMaxIndex(vector<float> &data)
{
    int result = 0;
    int size = data.size();
    for(int i = 1; i < size; i++)
        if(data[i] > data[result])
            result = i;

    return result;
}

float getVectorMinValue(vector<float> &data)
{
    return data[getVectorMinIndex(data)];
}

float getVectorMaxValue(vector<float> &data)
{
    return data[getVectorMaxIndex(data)];
}

void getVectorsMinIndexes(vector<vector<float>> &data, int &x, int &y)
{
    x = 0, y = 0;
    int size = data.size();
    for(int i = 0; i < size; i++)
    {
        int subsize = data[i].size();
        for(int j = 0; j < subsize; j++)
            if(getVectorMinValue(data[i]) < getVectorMinValue(data[x]))
                x = i;
    }

    y = getVectorMinIndex(data[x]);
}

void getVectorsMaxIndexes(vector<vector<float>> &data, int &x, int &y)
{
    x = 0, y = 0;
    int size = data.size();
    for(int i = 1; i < size; i++)
        if(getVectorMaxValue(data[i]) > getVectorMaxValue(data[x]))
            x = i;

    y = getVectorMaxIndex(data[x]);
}

float getVectorsMinValue(vector<vector<float>> &data)
{
    int x, y;
    getVectorsMinIndexes(data, x, y);
    return data[x][y];
}

float getVectorsMaxValue(vector<vector<float>> &data)
{
    int x, y;
    getVectorsMaxIndexes(data, x, y);
    return data[x][y];
}

void normalizeVector(vector<float> &data, float minRange, float maxRange, float minValue, float maxValue)
{
    int size = data.size();
    for(int i = 0; i < size; i++)
        data[i] = normalizeValue(data[i], minValue, maxValue, minRange, maxRange);
}

void normalizeVectors(vector<vector<float>> &data, float minRange, float maxRange)
{
    float minValue = getVectorsMinValue(data);
    float maxValue = getVectorsMaxValue(data);

    int size = data.size();
    for(int i = 0; i < size; i++)
        normalizeVector(data[i], minRange, maxRange, minValue, maxValue);
}
