#include "Vehicle.hpp"

void Vehicle::readFileForVeh(const std::string& filePath, const std::string& delimiter)
{
    std::string line, tmp;
    std::fstream input_file;
    DataForVeh temp{};
    input_file.open(filePath, std::fstream::in);
    //assert(input_file.is_open(), "File not there");
    int count = 0;
    while(getline(input_file, line, ',')) {
        if (count == 0) temp.stopwatch = stof(line);
        if (count == 1) temp.distance = stof(line);
        if (count == 2) temp.angle = stof(line);
        if (count == 3) temp.brake = stof(line);
        if (count == 4) temp.throttle = stof(line);
        count++;
        if (count == 5) { this->dataForVeh.push_back(temp); count = 0; }
    }
    input_file.close();
};


void Vehicle::debugPrint()
{
    for(const auto & i : this->dataForVeh)
    {
        std::cout << "Stopwatch: " << i.stopwatch << "Distance: " << i.distance << ", "
             << " Angle: " << i.angle << " Brake: " << i.brake << ", "
             << " Throttle: " << i.throttle << std::endl;
    }
};
