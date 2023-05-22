cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(simulator_0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#message("C++ compiler flags: ${CMAKE_CXX_FLAGS}")
list(APPEND flags "-Wall")
#if(NOT WIN32)
list(APPEND flags "-Wextra" "-Wpedantic")
#endif()

add_library(CarState CarState/CarState.cpp CarState/CarState.hpp)
add_library(Simulate Simulate/Simulate.cpp Simulate/Simulate.hpp)
add_library(Vehicle Vehicle/Vehicle.cpp Vehicle/Vehicle.hpp)
add_library(Formulas Formulas/Formulas.cpp Formulas/Formulas.hpp)
add_library(Scenario Scenario/Scenario.cpp Scenario/Scenario.hpp)
add_executable(simulator_0 main.cpp CarState/CarState.cpp Simulate/Simulate.cpp Scenario/Scenario.cpp Formulas/Formulas.cpp)

target_link_libraries(
    simulator_0 PUBLIC
    CarState
    Vehicle
    Simulate
    Scenario
    Formulas
)

