#include <iostream>
#include <thread>

#include "CarState.hpp"

void CarState::init()
{
    this->previousCycleStart = std::chrono::steady_clock::now();
    this->timeFrame = 0.0;
    this->timeTemp = 0.0;
}

void CarState::triggerAccelerationUntilSpeed(float acceleration_request, float targetSpeed)
{
    float factor;
    float milliseconds = 0.0;

    this->acceleration = this->getAcceleration(acceleration_request);
    if (this->acceleration < 0) { factor = -1.0; }
    if (this->acceleration > 0) { factor = 1.0; }
    this->setPedals(this->acceleration, factor);
    std::cout << "CAR Accelerating at " << this->acceleration << " ms2 !" << std::endl;

    while(factor * this->speed < targetSpeed) {
        this->now = std::chrono::steady_clock::now();
        milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(this->now - this->previousCycleStart).count();
        this->previousCycleStart = this->now;
        this->timeFrame = milliseconds / 1000;
        // calculate distance before speed since it is using the start speed
        this->distance += calculateDistance(this->acceleration, this->speed, this->timeFrame);
        this->accumulateSpeed();
        this->timeTotal += this->timeFrame;
        this->timeDriving += this->timeFrame;
        this->debugPrint();
        std::this_thread::sleep_for(std::chrono::milliseconds(FREQUENCY_STANDARD));
    }
}

void CarState::triggerAccelerationForTime(float acceleration_request, float targetTime)
{
    float factor;
    float milliseconds = 0.0;

    this->acceleration = getAcceleration(acceleration_request);
    if (this->acceleration < 0) { factor = -1.0; }
    if (this->acceleration > 0) { factor = 1.0; }
    this->setPedals(this->acceleration, factor);
    std::cout << "CAR Accelerating at " << this->acceleration << " ms2 !" << std::endl;

    while(this->timeTemp < targetTime) {
        this->now = std::chrono::steady_clock::now();
        milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(this->now - this->previousCycleStart).count();
        this->previousCycleStart = this->now;
        this->timeFrame = milliseconds / 1000;
        // calculate distance before speed since it is using the start speed
        this->distance += calculateDistance(this->acceleration, this->speed, this->timeFrame);
        this->accumulateSpeed();
        this->timeTotal += this->timeFrame;
        this->timeTemp += this->timeFrame;
        this->timeDriving += this->timeFrame;
        this->debugPrint();
        std::this_thread::sleep_for(std::chrono::milliseconds(FREQUENCY_STANDARD));
    }
    this->timeTemp = 0.0;
}

void CarState::accumulateSpeed()
{
    float result = this->speed + calculateSpeed(this->acceleration, this->timeFrame);
    if (result < 0) {result = 0;}
    this->speed = result;
}

float CarState::getAcceleration(float reqValue) const
{
    float result = reqValue;
    if (reqValue > this->getMaxAcceleration()) { result = maxAcceleration; }
    if (reqValue < this->getMaxDeacceleration()) { result = maxDeacceleration; }
    return result;
}

void CarState::setPedals(float acceleration_input, float factor)
{
    if (factor == 1.0) {
        this->gasPedal = acceleration_input / this->maxAcceleration;
        this->breakPedal = 0;
        return;
    }

    if (factor == -1.0) {
        this->gasPedal = 0;
        this->breakPedal = acceleration_input / this->maxDeacceleration;
    }
}

void CarState::stopCar()
{
    this->triggerAccelerationUntilSpeed(this->maxDeacceleration, 0);
    std::cout << "CAR STOPPED" << std::endl;
    this->debugPrint();
}

float CarState::getMaxAcceleration() const
{
    return 0.95 * this->maxAcceleration;
}

float CarState::getMaxDeacceleration() const
{
    return 0.95 * this->maxDeacceleration;
}

void CarState::debugPrint() const
{
    std::cout << "speed:" << this->speed << "\t";
    std::cout << "acceleration:" << this->acceleration << "\t";
    std::cout << "timeFrame:" << this->timeFrame << "\t";
    std::cout << "timeTotal:" << this->timeTotal << "\t";
    std::cout << "distance:" << this->distance << "\t";
    std::cout << "gasPedal:" << this->gasPedal << "\t";
    std::cout << "breakPedal:" << this->breakPedal << "\t";
    std::cout << "timeDriving:" << this->timeDriving << "\t";
    std::cout << "timeStanding:" << this->timeStanding << "\t" << std::endl;
}
