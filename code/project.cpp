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
}
