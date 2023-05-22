#include "Simulate.hpp"

CarState Simulate::runScenario(CarState carState, Scenario scenario)
{
    carState.init();
    if (scenario.speedFlag && scenario.speed > 0) {
        carState.triggerAccelerationUntilSpeed(DEFAULT_ACCELERATON, scenario.speed);
    }

    if (carState.speed > 0 && scenario.speedFlag && scenario.speed < carState.speed) {
        carState.triggerAccelerationUntilSpeed(-DEFAULT_ACCELERATON, scenario.speed);
    }

    if (scenario.accelerationFlag && scenario.acceleration != 0 && scenario.timeTotal != 0) {
        carState.triggerAccelerationForTime(scenario.acceleration, scenario.timeTotal);
    }

    return carState;
}


CarState Simulate::runTrack(CarState carState, Vehicle* vehicle) {
    carState.init();
    carState.runForVehicle(carState, *vehicle);
    return carState;
};
