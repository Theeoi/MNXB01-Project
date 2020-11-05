#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "tempTrender.h" //string is included here already.

using namespace std;

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

void tempTrender::setYear(int year) {
    pYear = year;
}

int tempTrender::getYear() {
    return pYear;
}

void tempTrender::setMonth(int month) {
    pMonth = month;
}

int tempTrender::getMonth() {
    return pMonth;
}

void tempTrender::setDay(int day) {
    pDay = day;
}

int tempTrender::getDay() {
    return pDay;
}

void tempTrender::setTemp(double temp) {
    pTemp = temp;
}

double tempTrender::getTemp() {
    return pTemp;
}

void tempTrender::setCountYear(int countYear) {
    pCountYear = countYear;
}

int tempTrender::getCountYear() {
    return pCountYear;
}

void tempTrender::setNumDays(int numDays) {
    pNumDays = numDays;
}

int tempTrender::getNumDays() {
    return pNumDays;
}

void tempTrender::tempPerDay() {
    
    std::ifstream file(pFilePath);
    if (!file)
        std::cerr << "tempPerDay could not read file: " << pFilePath << std::endl;
    // double fourthTrash;
    // int sixthTrash;

    std::vector<int> year, month, day;
    std::vector<double> temp;
    char comma;

    while (file) {

        file >> pYear >> pMonth  >> pDay  >> pTemp;

        year.push_back(pYear);
        month.push_back(pMonth);
        day.push_back(pDay);
        temp.push_back(pTemp);
    }
	cout << temp[i] << endl;
    for (long unsigned int i = 0; i < temp.size()-2;) {
        
            
        
        while (true) {
				if (year[i] != year[i+1]) {
					cout<<*max_element(temp.begin(),temp.end());
					cout<<*min_element(temp.begin(),temp.end());
					break;
				}
				else if (month[i] != month[i+1])
					break;
				else if (day[i] != day[i+1])
					break;
				else
					i++;
					
 



    }
}
}
