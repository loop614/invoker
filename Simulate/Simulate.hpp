#ifndef SIMULATE_HPP
#define SIMULATE_HPP

#include "../Scenario/Scenario.hpp"
#include "../CarState/CarState.hpp"
#include "../Vehicle/Vehicle.hpp"

#define DEFAULT_ACCELERATON 1

class Simulate
{
public:
    Simulate() = default;
    static CarState runScenario(CarState, Scenario);
    static CarState runTrack(CarState, Vehicle*);
    // CarState accelerate(CarState, float);
};

#endif // SIMULATE_HPP
