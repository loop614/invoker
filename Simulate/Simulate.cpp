#include "Simulate.hpp"

CarState Simulate::runScenario(CarState carState, Scenario scenario)
{
    carState.init();
    if (scenario.speedFlag && scenario.speed > 0 && scenario.speed > carState.speed) {
        carState.triggerAccelerationUntilSpeed(DEFAULT_ACCELERATION, scenario.speed);
    }

    if (scenario.speedFlag && carState.speed > 0 && scenario.speed < carState.speed) {
        carState.triggerAccelerationUntilSpeed(-DEFAULT_ACCELERATION, scenario.speed);
    }

    if (scenario.accelerationFlag && scenario.acceleration != 0 && scenario.timeTotal != 0) {
        carState.triggerAccelerationForTime(scenario.acceleration, scenario.timeTotal);
    }

    return carState;
}
