#ifndef TEMPTRENDER_H
#define TEMPTRENDER_H

#include <string>

class tempTrender {
	public:
        tempTrender(std::string filePath); //Construct using the specified file
	    ~tempTrender() {} //Destructor
        
        void setFilePath(std::string); 
        std::string getFilePath();

        void setIndMax(int); 
        int getIndMax();
        
        void setIndMin(int); 
        int getIndMin();
        
        void setYear(int);
        int getYear();
        
        void setMonth(int);
        int getMonth(); 

        void setDay(int); 
        int getDay();
        
        void setCountYear(int);
        int getCountYear();

        void setTemp(double); 
        double getTemp();
        
        void setMax(double);
        double getMax();

        
        void setMin(double);
        double getMin();
        
        void setTotMax(double);
        double getTotMax();
        
        void setTotMin(double);
        double getTotMin();

        
        void setAvMax(double);
        double getAvMax();
        
        void setAvMin(double);
        double getAvMin();
        
        void setTempDiff(double);
        double getTempDiff();

		void setTotDiff(double);
        double getTotDiff();
        
        void setAvDiff(double);
        double getAvDiff();
        
        
	    //void tempOnDay(int monthToCalculate, int dayToCalculate); //Make a histogram of the temperature on this day
	    //void tempOnDay(int dateToCalculate); //Make a histogram of the temperature on this date
	    //void tempPerDay(); //Make a histogram of the average temperature of each day of the year
	    void hotCold(); //Make a histogram of the hottest and coldest day of the year
	    //void tempPerYear(int yearToExtrapolate); //Make a histogram of average temperature per year, then fit and extrapolate to the given year

	private:
        std::string pFilePath;
	    int pIndMax;
        int pIndMin;
        int pYear;
        int pMonth;
        int pDay;
        int pCountYear;
        double pTemp;
        double pMax;
        double pMin; 
        double pTotMax;
        double pTotMin;
        double pAvMax;
        double pAvMin;
        double pTempDiff;
        double pTotDiff;
        double pAvDiff;

        
        
};

#endif
