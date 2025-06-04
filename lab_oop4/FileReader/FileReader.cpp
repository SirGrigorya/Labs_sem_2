#include "FileReader/FileReader.h"

#include "Normalization/NormalizationManager.h"
#include <fstream>
#include "FileReader/ExceptionFileReader.h"
#include "StringsManager.h"
#include <math.h>

using namespace std;

Scene* FileReader::readScene(string filename, NormalizationParameters params)
{
        vector<vector<string>> data = getData(filename);
        vector<vector<double>> values = convertToDouble(data);
        vector<Vertex>* verices = makeVerices(values);
        NormalizationManager::normalize(verices, params);
        vector<Edge>* edges = makeEdges(verices);
        Scene *scene = new Scene(verices, edges);
        return scene;
}

vector<vector<string>> FileReader::getData(string filename)
{
    fstream file(filename);
    if (!file)
        throw ExceptionFileReader("Error while opening file");

    vector<vector<string>> data;
    string str;

    while(getline(file, str))
    {
        if (!str.length())
            throw ExceptionFileReader("File contains empty string");

        vector<string> temp = StringManager::separateString(str, ',');
        data.push_back(temp);
    }
    if (data.size() != data[0].size())
        throw ExceptionFileReader("File is incorrect");

    return data;
}

vector<vector<double>> FileReader::convertToDouble(vector<vector<string>> &data)
{
    vector<vector<double>> values;


    size_t size = data.size();
    for (size_t i = 0; i < size; i++)
    {
        vector<double> temp;
        size_t tempSize = data[i].size();
        for (size_t j = 0; j < tempSize; j ++)
        {
            temp.push_back(atof(data[i][j].c_str()));
        }
        values.push_back(temp);
        temp.clear();
    }
    return values;
}

vector<Vertex>* FileReader::makeVerices(vector<vector<double> > &values)
{
    vector<Vertex>* verices = new vector<Vertex>();
    int counter = 0;
    verices->resize(values.size() * values.size());

    size_t size = values.size();

    for (size_t i = 0; i < size; i++)
    {
        size_t temp_size = values[i].size();
        for (size_t j = 0; j < temp_size; j++)
        {
            Point3D *point = new Point3D(i, j, values[i][j]);
            verices->at(counter).setPosition(point);
            counter++;
        }
    }
    return verices;
}

vector<Edge>* FileReader::makeEdges(vector<Vertex> *verices)
{
    vector<Edge>* edges = new vector<Edge>();

    size_t size = verices->size();

    for(size_t i = 0 ; i < size - 1; i++)
    {
        for(size_t j = i + 1; j < size; j++)
        {
            if(Point3D::isPoint3DNear(*verices->at(i).getPosition(), *verices->at(j).getPosition()))
            {
                Edge edge = Edge(verices->at(i), verices->at(j));
                edges->push_back(edge);
            }
        }
    }
    return edges;
}


