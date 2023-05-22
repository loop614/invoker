#ifndef FORMULAS_HPP
#define FORMULAS_HPP

#include <math.h>

float calcAccelerationST(float speed, float time);
float calcSpeedAT(float acceleration, float time);
float calcTimeAS(float acceleration, float speed);
float calcDistanceAST(float acceleration, float speed, float time);
float calcAccelerationDT(float distance, float time);
float calcTimeAD(float acceleration, float distance);

#endif // FORMULAS_HPP


