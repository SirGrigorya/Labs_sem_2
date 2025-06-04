#ifndef NORMALIZATION_MANAGER_H
#define NORMALIZATION_MANAGER_H

#include "Normalization/NormalizationParameters.h"
#include "Vertex.h"

class NormalizationManager
{
    public:
        static void normalize(std::vector<Vertex>* verices, NormalizationParameters params);
        static double getMax(std::vector<Vertex>* verices);
        static double getMin(std::vector<Vertex>* verices);
};

#endif // NORMALIZATION_MANAGER_H
