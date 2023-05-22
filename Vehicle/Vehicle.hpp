#ifndef TRACK_HPP_
#define TRACK_HPP_

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cassert>

class Vehicle
{
private:
    struct DataForVeh
    {
        float stopwatch;
        float distance;
        float angle;
        float brake;
        float throttle;
    };
    std::vector<DataForVeh> dataForVeh;

public:
    void readFileForVeh(const std::string&, const std::string&);
    void debugPrint();
};

#endif // TRACK_HPP_

