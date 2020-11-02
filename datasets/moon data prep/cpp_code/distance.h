#include <iostream> // Debugging.
#include <cmath>  // std::abs
#include <vector> // std::vector

int distance_from_full_moon(int year, int month, int day, std::vector<std::pair<std::string, std::vector<int>>> full_moon_dates){
    
    // The way this works is:
    // There is a full moon each month, but sometimes there can be two full moons in a month.
    // So, find the full moon that is in the same month. 
    // Figure out whether it was before of after the date.
    // If it was before, the next one will be after and vice versa.
    
    int size = full_moon_dates[0].second.size(); // We'll need to know the size of the full moon vector for later.
    int ind = 0; // Index of the full moon in that is the same year and month as given date.
    
    while ((full_moon_dates[0].second[ind] != year) || (full_moon_dates[1].second[ind] != month))
    {
        ind++;
    }
    int dist_same_month = std::abs(day - full_moon_dates[2].second[ind]);

    if (dist_same_month <= 15) // If full moon is closer than within 15 days, we are done.
    {
        return dist_same_month;
    }
    else // Else we need to do more colculations.
    {
        int distance = 30 - dist_same_month; // Since cycle of the moon is every 29.53 days, and we can calculate the other time distance.
        return distance;
    }
}