#include "Formulas.hpp"

float calcAccelerationST(float speed, float time)
{
    return speed / time;
}

float calcSpeedAT(float acceleration, float time)
{
    return acceleration * time;
}

float calcTimeAS(float acceleration, float speed)
{
    return speed / acceleration;
}

float calcDistanceAST(float acceleration, float speed, float time)
{
    return speed * time + 0.5 * acceleration * pow(time, 2);
}

float calcAccelerationDT(float distance, float time)
{
    return 2 * distance / pow(time, 2);
}

float calcTimeAD(float acceleration, float distance)
{
    return sqrt ( acceleration / 2 * distance );
}
