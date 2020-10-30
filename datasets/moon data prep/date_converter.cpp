#include <iostream>

#define MAX_DIGITS 10

int main(int argc, char *argv[])
{
    int day, month, year;
    day = 10*(argv[1][8]-'0') + (argv[1][9]-'0');
    month = 10*(argv[1][5]-'0') + (argv[1][6]-'0');
    year = 1000*(argv[1][0]-'0') + 100*(argv[1][1]-'0') + 10*(argv[1][2]-'0') + (argv[1][3]-'0');

    day = day - 14;
    if (day <= 0)
    {
        day = 30 + day;
        month = month - 1;
        if (month <= 0)
        {
            month = 12 + month;
            year = year - 1;
        }
    }
    
    char year_char[MAX_DIGITS + sizeof(char)];
    char month_char[MAX_DIGITS + sizeof(char)];
    char day_char[MAX_DIGITS + sizeof(char)];

    std::sprintf(year_char, "%d", year);
    std::sprintf(month_char, "%d", month);
    std::sprintf(day_char, "%d", day);

    //std::cout << day << std::endl;
    //std::cout << month << std::endl;
    //std::cout << year << std::endl;

    std::cout << year_char << "-";
    if (month < 10)
    {
        std::cout << "0" << month_char << "-";
    }
    else
    {
        std::cout << month_char << "-";
    }
    
    if (day < 10)
    {
        std::cout << "0" << day_char << std::endl;
    }
    else
    {
        std::cout << day_char << std::endl;
    }

    return 0;
}