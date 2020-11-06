#ifndef TEMPTRENDER_H
#define TEMPTRENDER_H

#include <string>
#include <TMath.h>

//double Gaussian(double* x, double* par) {
//    return par[0]*exp(-0.5*(x[0]*[0] - 2*x[0]*par[1] + par[1]*par[1]/(par[2]*par[2])));
//}

class tempTrender {
	public:
        tempTrender(std::string filePath); //Construct using the specified file
	    ~tempTrender() {} //Destructor
        
        void setFilePath(std::string); 
        std::string getFilePath();

        void setYear(int); 
        int getYear();
        
        void setMonth(int); 
        int getMonth(); 

        void setDay(int); 
        int getDay();

        void setTemp(double); 
        double getTemp();
        
        void setfirstYear(int);
        int getfirstYear();

	    //void tempOnDay(int monthToCalculate, int dayToCalculate); //Make a histogram of the temperature on this day
	    //void tempOnDay(int dateToCalculate); //Make a histogram of the temperature on this date
	    void tempPerValborg(); //Make a histogram of the average temperature of each day of the year
	    void hotCold(); //Make a histogram of the hottest and coldest day of the year
	    //void tempPerYear(int yearToExtrapolate); //Make a histogram of average temperature per year, then fit and extrapolate to the given year

	private:
        std::string pFilePath;
	    int pYear;
	    int pfirstYear;
        int pMonth;
        int pDay;
        double pTemp;
};

#endif
