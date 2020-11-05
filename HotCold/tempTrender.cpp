#include <iostream>
#include <fstream>
#include <vector>
#include "tempTrender.h" 
#include <bits/stdc++.h>

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
	

void tempTrender::hotCold() 
{
    
    std::ifstream file(pFilePath);

    if (!file)
        std::cerr << "hotCold could not read file: " << pFilePath << std::endl;

    std::vector<int> year, month, day;
    std::vector<double> temp, mtemp;
    
    pNumDays = 0;
    while(file >> pYear >> pMonth >> pDay >> pTemp)
    {
		temp.push_back(pTemp);
		while(pYear == 1722)
		{
			for(pMonth = 0; pMonth < 13; pMonth++)
			{
				for(long unsigned int = 0; i < 367; i++)
				{
					day.push_back(pNumDays);
					mtemp.push_back(pTemp);
					cout << temp[pTemp] << endl;
				}
			}
			
		}
	}
	//cout << "hello??" << temp[pTemp] << endl;
	
}
/* 
 
 for(long unsigned int = 0; i < 367; i++)
				
	year.push_back(pYear);
    month.push_back(pMonth);
    day.push_back(pDay);
    temp.push_back(pTemp);
	

    for (long unsigned int i = 0; i < year.size();)
    {
		cout << "YEAR: " << year.size() << endl;
		i++;
	}
}
         
    while (file >> pYear >> pMonth >> pDay >> pTemp) 
    {
        while(pCountYear == 1722 && pYear == pCountYear)
        {
			for(pMonth = 0; pMonth < 13; pMonth++)
			{
				for(pDay = 0; pDay < 13; pDay++)
				{
					//numDays++;
					//year.push_back(pYear);
					//cout << pYear << pDay << endl;
					//for(int i = 0; i < year; i++)
				}
				temp.push_back(pTemp);
				//cout << "Min: " << *min_element(year.begin(), year.end()) << endl;
				for(int i = 0; i < 367; i++)
				{
					std::cout << temp[i] << std::endl;
				}
				//Cant really get any loop to work... 
			}
		}
    }
 
}
 
*/
