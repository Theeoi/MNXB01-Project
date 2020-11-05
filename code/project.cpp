#include "tempTrender.h"
#include <string>

#include <TCanvas.h>

void project() {
    // START of Battle for Valborg!
    // Starting with Uppsala
    std::string uppsalaValborg = "../datasets/valborg_uppsala.csv"; //Put the path to your data file here
	tempTrender uppVal(uppsalaValborg); //Instantiate your analysis object
    
	uppVal.tempPerValborg();

    // Starting with Lund
    std::string lundValborg = "../datasets/valborg_lund.csv";
    tempTrender lundVal(lundValborg);

    lundVal.tempPerValborg();

    // END of Battle for Valborg!
=======
    std::string pathToFile = "../datasets/uppsala_tm_1722-2013.dat"; //Put the path to your data file here
	tempTrender t(pathToFile); //Instantiate your analysis object
	
	//t.tempOnDay(8, 23); //Call some functions that you've implemented
	//t.tempOnDay(235);
	//t.tempPerDay();
	t.hotCold();
	//t.tempPerYear(2050);

}
