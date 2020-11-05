#ifndef TEMPTRENDER_H
#define TEMPTRENDER_H

#include <string>

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
        
        void setCountYear(int);
        int getCountYear();
        
        void setNumDays(int);
        int getNumDays();

	    //void tempOnDay(int monthToCalculate, int dayToCalculate); //Make a histogram of the temperature on this day
	    //void tempOnDay(int dateToCalculate); //Make a histogram of the temperature on this date
	    //void tempPerDay(); //Make a histogram of the average temperature of each day of the year
	    void hotCold(); //Make a histogram of the hottest and coldest day of the year
	    //void tempPerYear(int yearToExtrapolate); //Make a histogram of average temperature per year, then fit and extrapolate to the given year

	private:
        std::string pFilePath;
	    int pYear;
        int pMonth;
        int pDay;
        double pTemp;
        int pCountYear;
        int pNumDays;
        
        
};

#endif
