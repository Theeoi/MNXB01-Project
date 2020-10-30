#include <iostream>
#include "tempTrender.h"

tempTrender::tempTrender(std::string filePath) {
    std::cout << "The user supplied " << filePath << " as the path to the data file." << std::endl;
    tempTrender::setFilePath(filePath);
}

void tempTrender::setFilePath(std::string filePath) {
    pFilePath = filePath;
}

std::string tempTrender::getFilePath() {
    return pFilePath;
}

void tempTrender::tempPerDay() {
    
    // Uppsala data only has average temperatures
    // If we don't find uppsala in filepath we must do some calculations first.
    std::string uppsala = "uppsala";
    if (pFilePath.find(uppsala) == std::string::npos) {
        std::cout << "We didn't find uppsala!" << std::endl;

        // Here we calculate the average temperature for each day. (If not uppsala data)
    }

    // Here we can start plotting the average temperature for each day (For uppsala we already have this)
    
}


