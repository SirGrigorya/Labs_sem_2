float normalizeValue(float value, float minValue, float maxValue, float minRange, float maxRange)
{
    return (minRange + (value - minValue) * (maxRange - minRange)/(maxValue - minValue));
}
