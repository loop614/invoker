#ifndef FORMULAS_HPP
#define FORMULAS_HPP

#include <math.h>

float calculateAccelerationSpeedOverTime(float speed, float time);
float calculateSpeed(float acceleration, float time);
float calculateTimeSpeedOverAcceleration(float acceleration, float speed);
float calculateDistance(float acceleration, float speed, float time);
float calculateAcceleration(float distance, float time);
float calculateTime(float acceleration, float distance);

#endif // FORMULAS_HPP


