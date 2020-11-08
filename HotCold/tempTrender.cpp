#include <iostream>
#include <fstream>
#include <vector>
#include "tempTrender.h" 
#include <bits/stdc++.h>
#include "TH1.h"
#include <TStyle.h> 
#include <TCanvas.h>

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

void tempTrender::setIndMax(int indMax) {
    pIndMax = indMax;
}

int tempTrender::getIndMax() {
    return pIndMax;
}

void tempTrender::setIndMin(int indMin) {
    pIndMin = indMin;
}

int tempTrender::getIndMin() {
    return pIndMin;
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

void tempTrender::setCountYear(int countYear) {
	pCountYear = countYear;
}

int tempTrender::getCountYear() {
	return pCountYear;
}

void tempTrender::setTemp(double temp) {
    pTemp = temp;
}

double tempTrender::getTemp() {
    return pTemp;
}

void tempTrender::setMax(double max) {
	pMax = max;
}

double tempTrender::getMax() {
	return pMax;
}

void tempTrender::setMin(double min) {
	pMin = min;
}
	
double tempTrender::getMin() {
	return pMin;
}

void tempTrender::setTotMax(double totMax) {
	pTotMax = totMax;
}
	
double tempTrender::getTotMax() {
	return pTotMax;
}
	

void tempTrender::setTotMin(double totMin) {
	pTotMin = totMin;
}
	
double tempTrender::getTotMin() {
	return pTotMin;
}

void tempTrender::setAvMax(double avMax) {
	pAvMax = avMax;
}
	
double tempTrender::getAvMax() {
	return pAvMax;
}

void tempTrender::setAvMin(double avMin) {
	pAvMin = avMin;
}
	
double tempTrender::getAvMin() {
	return pAvMin;
}
	
void tempTrender::setTempDiff(double tempDiff) {
	pTempDiff = tempDiff;
}
	
double tempTrender::getTempDiff() {
	return pTempDiff;
}

void tempTrender::setTotDiff(double totDiff) {
	pTotDiff = totDiff;
}
	
double tempTrender::getTotDiff() {
	return pTotDiff;
}

void tempTrender::setAvDiff(double avDiff) {
	pAvDiff = avDiff;
}
	
double tempTrender::getAvDiff() {
	return pAvDiff;
}


	
void tempTrender::hotCold()
{
	//make sure the file is accessible
    ifstream file(pFilePath);

    if (!file)
        cerr << "hotCold could not read file: " << pFilePath << std::endl;
	

    vector<int> year;
    vector<float> temp, max, min, diff;
	
	//read in file and save year and temperadure in vectors
	while(file >> pYear >> pMonth >> pDay >> pTemp)
	{
		year.push_back(pYear);
		temp.push_back(pTemp);
	}

	//close file as we have gathered all data we need.
	file.close();
	
	//hist for hottest/coldest temp of the year, nr of entries	
    TH1D* histHot = new TH1D("histHot", "Histogram; Temperature; Entries", 150, -40, 40);
    TH1D* histCold = new TH1D("histCold", "Histogram; Temperature; Entries", 150, -40, 40);

	//assuming here that max temp > 0 and min temp < 0, 
	//start count year at 1722, which is the first entry in <year>
	double pMax = 0;
	double pMin = 0;
	pCountYear = 1722;
	
	//loop to find max for each year and store it in a vector <max>
	for(long unsigned int i = 0; i < year.size(); i++) 
	{
		if(year[i] == pCountYear)
		{
			if(temp[i] > pMax || pMax == 0)
			{
				pMax = temp[i];
			}
		}
		else
		{
			max.push_back(pMax);
			pMax = 0;
			pCountYear++;
		}
	}
	
	pCountYear = 1722; //set year counter back to 1722
	
	//loop to find min for each year and store it in a vector <min>
	for(long unsigned int i = 0; i < year.size(); i++) 
	{
		if(year[i] == pCountYear)
		{
			if(temp[i] < pMin || pMin == 0)
			{
				pMin = temp[i];
			}
		}
		else
		{
			min.push_back(pMin);
			pMin = 0;
			pCountYear++;
		}
	}
	
	//histogram for hottest day for each year
	TH1D* histHot2 = new TH1D("histHotCold", "Uppsala year by year; Year; Temperature [C]", max.size(), 1722, 2013);
	
	//histogram for coldest day for each year
	TH1D* histCold2 = new TH1D("histHotCold", "Uppsala year by year; Year; Temperature [C]", max.size(), 1722, 2013);
	
	//TCanvas* c1 = new TCanvas("cl", "Uppsala highs and lows", 900, 600);

	pCountYear = 1722;
	pTotMax = 0;
	
	//loop and fill 4 histograms (max and min has same size = 291)
	//not all years have data! there are some years for when the data 
	//was taken from other places than uppsala, those places where removed in the cleaning process. 
	for(long unsigned int n = 0; n < max.size(); n++)
	{	
		histHot->Fill(max[n]); 
		histCold->Fill(min[n]);
		histHot2->Fill(pCountYear, max[n]);
		histCold2->Fill(pCountYear, min[n]);
		pTotMax = pTotMax + max[n]; 
		pTotMin = pTotMin + min[n];
		pTempDiff = max[n] - min[n];
		diff.push_back(pTempDiff);
		pCountYear = pCountYear + 1;
	}
	
	//calculate average for max/min temperatures
	pAvMax = pTotMax/max.size(); 
	pAvMin = pTotMin/min.size();
	
	cout << "Average yearly maximum is: " << pAvMax << endl;
	cout << "Average yearly minimum is: " << pAvMin << endl;
	
	pTotDiff = 0;
	for(long unsigned int i = 0; i < diff.size(); i++)
	{
		pTotDiff = pTotDiff + diff[i];
	}
	pAvDiff = pTotDiff/diff.size();
	
	cout << "Average yearly difference: " << pAvDiff << endl;	
	
	//fill the histograms with the right colour and draw them together
	histHot2->SetMinimum(-35);
	histHot2->SetMaximum(35);
	histHot2->SetLineColor(2);
	histHot2->SetFillColor(2);
	
	histCold2->SetMinimum(-35);
	histCold2->SetLineColor(4);
	histCold2->SetFillColor(4);
	
	histHot2->Draw("hist b");
	histCold2->Draw("hist same b");
}	
/*	
 	//hist with nr of entries for hottest/coldest days
	histHot->SetMinimum(0);
	histHot->SetLineColor(2);
	histHot->Draw();
	histCold->SetMinimum(0);
	histCold->SetLineColor(4);
	histCold->Draw("same");

 * //this method only works when we have vectors with temperature for each year!
 * // but then you have to have this text inside the loop and thats no good...
	cout << temp.size() << endl;
	pIndMax = max_element(temp.begin(), temp.end()) - temp.begin();
	pIndMin = min_element(temp.begin(), temp.end()) - temp.begin();
	pMax = *max_element(temp.begin(), temp.end());
	pMin = *min_element(temp.begin(), temp.end());
	cout << "max: " << pMax << " index: " << pIndMax << endl;
	cout << "min: " << pMin << " index: " << pIndMin << endl;
	cout << year.size() << endl;
	data.push_back(pMax);	

 
*/
