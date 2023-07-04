#include "Formulas.hpp"

float calculateAccelerationSpeedOverTime(float speed, float time)
{
    return speed / time;
}

float calculateSpeed(float acceleration, float time)
{
    return acceleration * time;
}

float calculateTimeSpeedOverAcceleration(float acceleration, float speed)
{
    return speed / acceleration;
}

float calculateDistance(float acceleration, float speed, float time)
{
    return speed * time + 0.5 * acceleration * pow(time, 2);
}

float calculateAcceleration(float distance, float time)
{
    return 2 * distance / pow(time, 2);
}

float calculateTime(float acceleration, float distance)
{
    return sqrt ( acceleration / 2 * distance );
}
