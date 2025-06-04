#include "Normalization/NormalizationManager.h"

using namespace std;


void NormalizationManager::normalize(std::vector<Vertex>* verices, NormalizationParameters params)
{
    double max = getMax(verices);
    double min = getMin(verices);
    Point3D* point;

    size_t size = verices->size();

    for (size_t i = 0; i < size; i++)
    {
        point = verices->at(i).getPosition();
        point->Z = params.min + ((point->Z - min)*(params.max - params.min) / (max - min));
    }
}

double NormalizationManager::getMax(vector<Vertex> *verices)
{
    Point3D* point = verices->at(0).getPosition();
    double max = point->Z;
    size_t size = verices->size();
    for (size_t i = 0; i < size; i++)
    {
        point = verices->at(i).getPosition();
        if (max < point->Z)
            max = point->Z;
    }
    return max;
}

double NormalizationManager::getMin(vector<Vertex> *verices)
{
    Point3D* point = verices->at(0).getPosition();
    double min = point->Z;

    size_t size = verices->size();
    for (size_t i = 0; i < size; i++)
    {
        point = verices->at(i).getPosition();
        if (min > point->Z)
            min = point->Z;
    }
    return min;
}
