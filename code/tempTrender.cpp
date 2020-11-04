#include <iostream>
#include <fstream>
#include <vector>
#include "tempTrender.h" //string is included here already.

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
        file >> pYear >> comma >> pMonth >> comma >> pDay >> comma >> pTemp;

        year.push_back(pYear);
        month.push_back(pMonth);
        day.push_back(pDay);
        temp.push_back(pTemp);
    }
 
    for (long unsigned int i = 0; i < temp.size() - 2;) {
        
        long unsigned int sIndex = i;    
        
        while (true) {
                if (year[i] != year[i+1])
                    break;
                else if (month[i] != month[i+1])
                    break;
                else if (day[i] != day[i+1])
                    break;
                else
                    i++;
        }

        long unsigned int eIndex = i++;
        
        double avgTemp = 0.;
        for (long unsigned int j = sIndex; j <= eIndex; j++) {
            
            avgTemp += temp[j];
            
        }

        std::cout << "avgTemp of day " << year[sIndex] << "-" << month[sIndex] << "-" 
            << day[sIndex] << " is: " << avgTemp/(eIndex - sIndex + 1) << std::endl;


    }

    // TODO:
    // - Read in the data properly... (Should work for all files!)
    // - Find all temperatures of each date and fit them to a gaussian (if only one temp -> do not do this)
    // - Calculate the mean of the gaussian = Mean temp for the day (if only one temp, set to average directly)
    // - Plot everything nicely.


} // END of tempPerDay()
    
    //for hotcold, Make a histogram of the hottest and coldest day of the year

/*
void tempTrender::hotCold() { 
    std::ifstream file("filePath"); //open input file 
     
    if( "some statement to be checked for content of file" )
        std::cout << "Error: the file content did not match the expected" << std::endl;
    int n = 0; //counter initialized
    std::string helpString; //help variable
     
    while(getline(file, helpString) n++; ) nEntries = n;//to get number of entries in dataset
     
      //Notes: "pick out" correct data from file
      //Use for maximum? Int_t binmax = hist->GetMaximumBin(); Double_t x = hist->GetXaxis()->GetBinCenter(binmax) 
      //How do we get what binnumber this corresponds to?
      //How to do for data from uppsala AND lund data file at the same time? do separately and "draw" in same histogram?
      //Set start year somehow. 
    std::cout << "Year" << year << "Month :" << month << "Date : " << date <<  std::endl;
    nEntries++;
  
}
*/
/*

 // from project instructions to get the mean/plot right.
double Gaussian(double* x, double* par) {
    return par[0]*exp(-0.5*(x[0]*[0] - 2*x[0]*par[1] + par[1]*par[1]/(par[2]*par[2]));
}

TF1* func= new TF1("Gaussian", Gaussian, 1, 366, 3);
func->SetParameters(5, 200, 50); //Starting values for fitting
hist->Fit(func, "Q0R");

cout << "The mean is " << func->GetParameter(1) << endl;
cout << "Its uncertainty is " << func->GetParError(1) << endl;

TLegend *leg = new TLegend(0.65, 0.75, 0.92, 0.92, "", "NDC");
leg->SetFillStyle(0);//Transparent fill
leg->SetBorderSize(0);//Get rid of the border
leg->AddEntry(hist, "", "F"); //Use object title draw fill
leg->AddEntry(anotherHist, "A title", "F"); //Use custom title

hist->Draw();
anotherHist->Draw("SAME"); //To get it in the same plot
leg->Draw(); //Legends dont need "SAME" to be drawn in same plot

*/ 



