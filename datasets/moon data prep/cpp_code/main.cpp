#include <iostream>

#include "read_csv_double.h"
#include "read_csv_int.h"
#include "write_csv_int.h"
#include "distance.h"

int main(){
    // Opening 2 CSV files we need.
    std::vector<std::pair<std::string, std::vector<int>>> full_moon_dates = read_csv_int("full-moon_only_dates.csv");
    std::vector<std::pair<std::string, std::vector<int>>> non_moon_dates = read_csv_int("non-moon_only_dates.csv");

    std::vector<int> distances; // vector to store all the distances (how many days) to the full moon.
    std::vector<int> full_distances(full_moon_dates[0].second.size(), 0); // vector to store all the distances (how many days) to the full moon.

    int size = non_moon_dates[0].second.size();
    for (int i = 0; i < size; i++)
    {
        int year = non_moon_dates[0].second[i];
        int month = non_moon_dates[1].second[i];
        int day = non_moon_dates[2].second[i];

        distances.push_back(distance_from_full_moon(year, month, day, full_moon_dates));
    }
    
    std::vector<std::pair<std::string, std::vector<int>>> vals = {{"Dist", distances}};
    std::vector<std::pair<std::string, std::vector<int>>> vals2 = {{"Dist", full_distances}}; 
    write_csv_int("non-moon_only_distances.csv", vals); // Wooohooo!! Saving the csv file!
    write_csv_int("full-moon_only_distances.csv", vals2); // Wooohooo!! Saving the csv file!
    return 0;
}