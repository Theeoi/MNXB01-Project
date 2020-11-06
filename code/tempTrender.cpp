#include <iostream>
#include <fstream>
#include <vector>
#include "tempTrender.h" //string is included here already.

#include <TH1.h>
#include <TF1.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TText.h>
#include <TCanvas.h>
#include <TLegend.h>

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

void tempTrender::setfirstYear(int firstYear) {
    pfirstYear = firstYear;
}

int tempTrender::getfirstYear() {
    return pfirstYear;
}

void tempTrender::tempPerValborg() { // START of tempPerValborg()
 
    std::ifstream file(pFilePath);

    if (!file)
        std::cerr << "tempPerValborg could not read file: " << pFilePath << std::endl;

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

    file.close();

    TH1D* hist = new TH1D("hist", "Histogram", temp.size(), 0, temp.size());

    const char* canvasName = pFilePath.c_str();
    TCanvas* c1 = new TCanvas(canvasName, "tempPerValborg", 2500, 900);

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
        
        for (long unsigned int j = sIndex; j <= eIndex; j++) {
    
            hist -> Fill(j, temp[j]);

        }
        
        hist -> Draw("SAME");

        char str[temp.size()];
        sprintf(str,"fit%u",static_cast<unsigned int>(sIndex));

        TF1* fGaus = new TF1(str, "gaus", sIndex, eIndex + 1);
        fGaus -> SetParameters(10, (eIndex - sIndex + 1)/2, 1);
        fGaus -> SetParLimits(0, -5, 35);
        
        hist -> Fit(fGaus, "QR+");
        
        std::string yearStr = std::to_string(year[sIndex]);
        std::string monthStr = std::to_string(month[sIndex]);
        std::string dayStr = std::to_string(day[sIndex]);

        std::string dateStr = yearStr + "-" + monthStr + "-" + dayStr;
        const char* dateChar = dateStr.c_str();

        TText* date = new TText((eIndex + sIndex + 1)/2, fGaus -> GetParameter(0), dateChar);
        date -> SetTextAngle(60);
        date -> SetTextSize(.02);
        date -> Draw();
        
    }
    
    hist -> GetXaxis() -> SetTitle("Data Point [Arb. Unit]");
    hist -> GetYaxis() -> SetTitle("Temperature [C]");
    hist -> GetXaxis() -> CenterTitle(true);
    hist -> GetYaxis() -> CenterTitle(true);

    TLegend *leg = new TLegend(0.65, 0.75, 0.92, 0.92, "", "NDC");
    leg -> SetFillStyle(0);//Transparent fill
    leg -> SetBorderSize(0);//Get rid of the border
    leg -> SetTextSize(.05);

    std::string uppStr = "uppsala";
    std::string lundStr = "lund";
    if (pFilePath.find(uppStr) != std::string::npos) { //The data is from uppsala
        
        TLegend *leg = new TLegend(0.65, 0.80, 0.92, 0.92, "Battle for Valborg! - uppsala", "NDC");
        leg -> SetFillStyle(0);//Transparent fill
        leg -> SetBorderSize(0);//Get rid of the border
        //gStyle -> SetLegendTextSize(.05);
        leg -> Draw();

        c1 -> Update(); 
        c1 -> SaveAs("./BfV/BfV-uppsala.png");

        hist -> GetXaxis() -> SetRangeUser(224,276);

        c1 -> Update();
        c1 -> SaveAs("./BfV/uppsala-LundRange.png");

        hist -> GetXaxis() -> SetRangeUser(195,200);

        c1 -> SetCanvasSize(1200,900);
        c1 -> Update();
        c1 -> SaveAs("./BfV/uppsala-Coldest.png");

    }
    else if (pFilePath.find(lundStr) != std::string::npos) { //The data is from Lund
        
        TLegend *leg = new TLegend(0.65, 0.80, 0.92, 0.92, "Battle for Valborg! - Lund", "NDC");
        leg -> SetFillStyle(0);//Transparent fill
        leg -> SetBorderSize(0);//Get rid of the border
        //gStyle -> SetLegendTextSize(.05);
        leg -> Draw();

        c1 -> Update(); 

        c1 -> SaveAs("./BfV/BfV-Lund.png");

    }
    else
        std::cout << "The data is neither from uppsala or Lund. No plotting is done.\n"; 
    
    // TODO:
    // - Make plot look nice!
    //
    // BUGS:
    // - Fitting does not work for negative temperatures. Should add a constant fitting parameter to get this to work.

} // END of tempPerValborg()
  
    //for hotcold, Make a histogram of the hottest and coldest day of the year

/*
void tempTrender::hotCold() { 
    std::ifstream file(pFilePath); //open input file 

    if (!file)
        std::cerr << "hotCold could not read file: " << pFilePath << std::endl;
    
    std::vector<int> year, month, day;
    std::vector<double> temp;
    
    while (file) {
        file >> pYear >> pMonth >> pDay >> pTemp;

        year.push_back(pYear);
        month.push_back(pMonth);
        day.push_back(pDay);
        temp.push_back(pTemp);
    }
    
    
    int n = 0; //counter initialized
    std::string helpString; //help variable?
    
    while(getline(file, helpString) n++; ) nEntries = n;//to get number of entries in dataset?
     
      //Notes: "pick out" correct data from file
      //Use for maximum? Int_t binmax = hist->GetMaximumBin(); Double_t x = hist->GetXaxis()->GetBinCenter(binmax) 
      //How do we get what binnumber this corresponds to?
      //How to do for data from uppsala AND lund data file at the same time? do separately and "draw" in same histogram?
      //Set start year somehow. 
    
    std::cout << "Year" << year << "Month :" << month << "Date : " << date <<  std::endl;
    nEntries++;
    
    TH1D* histHot = new TH1D("histHot", "Histogram", 366, 1, 366); 
    TH1D* histCold = new TH1D("histCold", "Histogram", 366, 1, 366); 

    pfirstYear = 1722;
    while (file >> pYear >> pMonth >> pDay >> pTemp) {
       
       if (pYear == pfirstYear) {
         temp.push_back(pTemp);
         histHot->Fill(*max_element(temp.begin(),temp.end()));
         histCold->Fill(*min_element(temp.begin(),temp.end()));
        }
       else
         pfirstYear += 1;
	}
    //cout << temp[] << endl;
       
      histHot->Draw();
      histCold->Draw("same");
 }      
      //??->??("histhotCold", "x", "y"); //read in data and set the right parameters?
      histhotCold->Fill();
      histhotCold->GetMean();//or use the more fancy way below
      histhotCold->GetStdDev();
      
      

*/
/*

 // from project instructions to get the mean/plot right.
double Gaussian(double* x, double* par) {
    return par[0]*exp(-0.5*(x[0]*[0] - 2*x[0]*par[1] + par[1]*par[1]/(par[2]*par[2]));
}

TF1* func= new TF1("Gaussian", Gaussian, 1, 366, 3);
func->SetParameters(5, 200, 50); //Starting values for fitting
histhotCold->Fit(func, "Q0R");

cout << "The mean is " << func->GetParameter(1) << endl;
cout << "Its uncertainty is " << func->GetParError(1) << endl;

TLegend *leg = new TLegend(0.65, 0.75, 0.92, 0.92, "", "NDC");
leg->SetFillStyle(0);//Transparent fill
leg->SetBorderSize(0);//Get rid of the border
leg->AddEntry(hist, "", "F"); //Use object title draw fill
leg->AddEntry(anotherHist, "A title", "F"); //Use custom title

histhotCold->Draw();
anotherHist->Draw("SAME"); //To get it in the same plot
leg->Draw(); //Legends dont need "SAME" to be drawn in same plot

*/



