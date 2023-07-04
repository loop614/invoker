#include <iostream>
#include "Scenario/Scenario.hpp"
#include "CarState/CarState.hpp"
#include "Simulate/Simulate.hpp"
#include "Vehicle/Vehicle.hpp"

using namespace std;

int main()
{
    CarState carState;
    Simulate simulate;
    Scenario scenario;

    //START:: SPEED SCENARIO
    scenario.speedFlag = true;
    scenario.speed = 2.0;
    carState = Simulate::runScenario(carState, scenario);

    scenario.speed = 0.0;
    carState = simulate.runScenario(carState, scenario);
    scenario.speedFlag = false;
    //END:: SPEED SCENARIO

    //START:: ACCELERATION SCENARIO
    scenario.accelerationFlag = true;
    scenario.acceleration = 2.0;
    scenario.timeTotal = 2.0;
    carState = simulate.runScenario(carState, scenario);

    scenario.acceleration = -2.0;
    scenario.timeTotal = 2.0;
    carState = simulate.runScenario(carState, scenario);
    scenario.accelerationFlag = false;
    //END:: ACCELERATION SCENARIO
    return 0;
}


int main2()
{
    Vehicle *porsche = new Vehicle();
    porsche->readFileForVeh("../Assets/for_veh.csv", ",");
    porsche->debugPrint();

    return 0;
}
