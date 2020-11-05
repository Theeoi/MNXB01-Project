#include <iostream>

// Lets try and read the CSV.
auto df = ROOT::RDF::MakeCsvDataFrame("final_file.csv");
TLinearFitter *lf=new TLinearFitter(3);
lf ->SetFormula("x ++ y ++ z");

