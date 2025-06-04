#include <math.h>

float fromRadToAng(float rad)
{
    return (rad / M_PI * 180.0);
}

float fromAngToRad(float ang)
{
    return (ang / 180.0 * M_PI);
}
