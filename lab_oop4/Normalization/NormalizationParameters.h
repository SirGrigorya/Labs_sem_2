#ifndef NORMALIZATIONPARAMETERS_H
#define NORMALIZATIONPARAMETERS_H


class NormalizationParameters
{
    public:
        float min;
        float max;
        float stepX;
        float stepY;
        NormalizationParameters(float min, float max, float stepX, float stepY);
};

#endif // NORMALIZATIONPARAMETERS_H
