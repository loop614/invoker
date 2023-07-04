#include <iostream>
#include <fstream>
#include <string>

#include "Vehicle.hpp"

void Vehicle::readFileForVeh(const std::string& filePath, const std::string& delimiter)
{
    std::fstream input_file;
    DataForVeh temp = {0};
    input_file.open(filePath, std::fstream::in);
    if (!input_file.is_open()) {
        std::cout << "file failed to open" << std::endl;
        return;
    }

    std::string line, token;
    size_t pos = 0;
    int count = 0;
    while(std::getline(input_file, line, '\r')) {
        if (line.size() < 9) { continue; }
        line.append(delimiter);

        while ((pos = line.find(delimiter)) != std::string::npos) {
            token = line.substr(0, pos);
            // stopwatch;distance;angle;brake;throttle;
            // 0.000,0,0,0,100
            if (count == 0) temp.stopwatch = stof(token);;
            if (count == 1) temp.distance = stof(token);
            if (count == 2) temp.angle = stof(token);
            if (count == 3) temp.brake = stof(token);
            if (count == 4) temp.throttle = stof(token);

            count++;
            if (count == 5) {
                this->dataForVeh.push_back(temp);
                count = 0;
            }
            line.erase(0, pos + delimiter.length());
        }
    }
    input_file.close();
};


void Vehicle::debugPrint()
{
    for(const auto & i : this->dataForVeh)
    {
        std::cout << "Stopwatch: " << i.stopwatch << "\t Distance: " << i.distance <<
             "\t Angle: " << i.angle << "\t Brake: " << i.brake << "\t "
             << "\t Throttle: " << i.throttle << std::endl;
    }
};
