#include <iostream>
#include <fstream>
#include <vector>
#include "tempTrender.h" 
#include <bits/stdc++.h>
#include "TH1.h"

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


	TH1D* histHotCold = new TH1D("histHotCold", "Histogram", 366, 1, 366);	
    TH1D* histHotCold = new TH1D("histHotCold", "Histogram", 366, 1, 366);
	

    std::vector<int> year, month, day;
    std::vector<float> temp;

	while(file >> pYear >> pMonth >> pDay >> pTemp)
	{
		if(pYear == 1722)
		{
			temp.push_back(pTemp);
		}
	}
	for(long unsigned int i = 0; i < temp.size(); i++)
	{
		cout << i << " : " << temp[i] << endl;
	}
		cout << temp.size() << endl;

	cout << temp.size() << endl;
	pIndMax = max_element(temp.begin(), temp.end()) - temp.begin(); //creating index for max value 
	pIndMin = min_element(temp.begin(), temp.end()) - temp.begin(); ////creating index for min value 
	pMax = *max_element(temp.begin(), temp.end()); //finding max
	pMin = *min_element(temp.begin(), temp.end()); //finding min
	cout << "max: " << pMax << " index: " << pIndMax << endl;
	cout << "min: " << pMin << " index: " << pIndMin << endl;
}	
/*
This loop is storing the max and min values of the vector 'temp' stored with temperature values for one year, the first one.
Need to add some kind of loop for the years aswell.


		year.push_back(pYear);
		
		for(long unsigned int i = 0; i <)
		if(pYear == 1722)
		{
			temp.push_back(pTemp);
			cout << temp[pTemp] << endl;
		}	
		
		
	}
	for(long unsigned int i = 0; i < temp.size(); i++)
	{
		cout << "TEMP: " << temp[i+1] << endl;
	
	    year.push_back(pYear);
		month.push_back(pMonth);
		day.push_back(pDay);
		temp.push_back(pTemp);
    }
    
    while(year[pYear] == 1722 && month[pMonth] < 2)
    {
		for(long unsigned int i = 0; i < 367; i++)
		{
			info.push_back(temp[i]);
			cout << info[i] << endl;
		}
	}
<<<<<<< HEAD
}
	

	for(long unsigned int i = 0; i < temp.size(); i++)
	{ 
		cout << temp[i] << "  WHAT " << temp[i+1] << " WHAT " << temp.size() << endl;
		//give index i to each temperature in temp?
	}
	
=======
>>>>>>> 0aea0f2aabc16aac02c720a32cfce876120e1ec7
}

	

  
 year.push_back(pYear);
		month.push_back(pMonth);
		day.push_back(pDay);
		temp.push_back(pTemp);
 
 for(long unsigned int = 0; i < 367; i++)
				
	

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
				I know im doing this way wrong and more complicated than it needs to be
			}
		}
    }
 
}
 
*/
