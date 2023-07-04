#ifndef CARSTATE_HPP
#define CARSTATE_HPP

#include <chrono>

#include "../Formulas/Formulas.hpp"
#include "../Scenario/Scenario.hpp"
#include "../Vehicle/Vehicle.hpp"

#define FREQUENCY_STANDARD 500


class CarState
{
public:
    CarState() {
        this->speed = 0.0;
        this->acceleration = 0.0;
        this->gasPedal = 0.0;
        this->breakPedal = 1.0;
        this->timeTotal = 0.0;
        this->timeDriving = 0.0;
        this->timeStanding = 0.0;
        this->distance = 0.0;
        this->steeringAngle = 0.0;
        this->orientation = 0.0;
        this->altitude = 0.0;
    }
    float speed;
    float acceleration;
    float gasPedal;
    float breakPedal;
    float timeTotal;
    float timeTemp;
    float timeFrame;
    float timeDriving;
    float timeStanding;
    float distance;
    float altitude;
    float steeringAngle;
    float orientation;
    float maxAcceleration = 5.55;
    float maxDeacceleration = -18;

    std::chrono::time_point<std::chrono::steady_clock> previousCycleStart;
    std::chrono::time_point<std::chrono::steady_clock> now;

public:
    void init();
    void triggerAccelerationUntilSpeed(float, float);
    void triggerAccelerationForTime(float value, float time);
    void setPedals(float, float);
    void accumulateSpeed();
    float getAcceleration(float) const;
    float getMaxAcceleration() const;
    float getMaxDeacceleration() const;
    void debugPrint() const;
    void stopCar();
};

#endif // CARSTATE_HPP
