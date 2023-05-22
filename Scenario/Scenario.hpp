#ifndef SCENARIO_0_HPP
#define SCENARIO_0_HPP

#include "../CarState/CarState.hpp"

class Scenario
{
public:
    Scenario() {
        this->speedFlag = false;
        this->speed = 0.0;
        this->accelerationFlag = false;
        this->acceleration = 0.0;
        this->distanceFlag = false;
        this->distance = 0.0;
        this->gasPedalFlag = false;
        this->gasPedal = 0.0;
        this->breakPedalFlag = false;
        this->breakPedal = 0.0;
        this->timeTotal = 0.0;
        this->timeStandingFlag = false;
        this->timeStanding = 0.0;
    }
    bool speedFlag;
    float speed;
    bool accelerationFlag;
    float acceleration;
    bool distanceFlag;
    float distance;
    bool gasPedalFlag;
    float gasPedal;
    bool breakPedalFlag;
    float breakPedal;
    float timeTotal;
    bool timeStandingFlag;
    float timeStanding;
};


#endif // SCENARIO_0_HPP


