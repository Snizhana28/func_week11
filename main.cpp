// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com


/*Task 1. Write a function that accepts two dates
(that is, the function takes six parameters) and calculates
the difference in days between these dates. To do this
the task is also to write a function that determines whether a year is a leap year.*/

#include <iostream>
using namespace std;

int leapYear(int year)
{
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)   
        return 1;
    else
        return 0;
}

int dayMount(int month, int year)
{
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        return 31;

    if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;

    if (month == 2)
    {
        int x = leapYear(year);
        if (x == 1)   
            return 29;
        else
            return 28;
    }
}

int differenceDays(int day1, int month1, int year1, int day2, int month2, int year2)
{
    if (year1 == year2)
    {
        if (month1 == month2)
        {
            int result = 0;
            if (day1 == day2)                   // same dates
                return 0;
            else
                return result = (day1 - day2);  // same years & months but different days
        }
        else if (month1 < month2)
        {
            int result = 0;
            for (int i = month1; i < month2; i++)
                result += dayMount(i, year1);

            if (day1 == day2)                   // same years & days but different months 
                return result;
            else if (day1 < day2)               // y1=y2 , m1<m2 , d1<d2
            {
                result += (day2 - day1);
                return result;
            }
            else                                // y1=y2 , m1<m2 , d1>d2 
            {
                result -= (day1 - day2);
                return result;
            }
        }
        else                                    // m1>m2
        {
            int result = 0;
            for (int i = month2; i < month1; i++)
                result += dayMount(i, year1);

            if (day1 == day2)                   // same years & days but different months 
                return result;
            else if (day2 < day1)               // y1=y2 , m1>m2 , d2<d1 
            {
                result += (day1 - day2);
                return result;
            }
            else
            {
                result -= (day2 - day1);        // y1=y2 , m1>m2 , d2>d1 
                return result;
            }
        }
    }
    else if (year1 < year2)                     // y1<y2
    {
        int temp = 0;
        for (int i = year1; i < year2; i++)
        {
            if (leapYear(i))
                temp += 366;
            else
                temp += + 365;
        }

        if (month1 == month2)
        {
            if (day1 == day2)                   //same months & days but different years
                return temp;
            else if (day1 < day2)               // m1=m2 , d2>d1 , y1<y2
                return temp + (day2 - day1);
            else
                return temp - (day1 - day2);   // m1=m2 , d1>d2 , y1<y2
        }
        else if (month1 < month2)
        {
            int result = 0;
            for (int i = month1; i < month2; i++)
                result += dayMount(i, year2);

            if (day1 == day2)                  // same days, different years & months
                return temp + result;
            else if (day1 < day2)              // m1<m2 , d1<d2 , y1<y2
            {
                result += (day2 - day1);
                return temp + result;
            }
            else                                // m1<m2 , d1>d2 , y1<y2
            {
                result -= (day1 - day2);
                return temp + result;
            }
        }
        else                                    //m1>m2
        {
            int result = 0;
            for (int i = month2; i < month1; i++)
                result += dayMount(i, year2);

            if (day1 == day2)                   // same days, different years & months
                return temp - result;
            else if (day2 < day1)               // m1>m2 , d1>d2 , y1<y2
            {
                result += (day1 - day2);
                return temp - result;
            }
            else
            {
                result -= (day2 - day1);        // m1>m2 , d1<d2 , y1<y2
                return temp - result;
            }
        }
    }
    else                                        // y1>y2
    {
        int temp = 0;
        for (int i = year2; i < year1; i++)
        {
            if (leapYear(i))
                temp += 366;
            else
                temp += 365;
        }

        if (month1 == month2)
        {
            if (day1 == day2)                   // same days  & months but different years
                return temp;
            else if (day2 < day1)               // m1=m2 , d1>d2 , y1>y2
                return temp + (day1 - day2);
            else
                return temp - (day2 - day1);    // m1=m2 , d1<d2 , y1>y2
        }
        else if (month2 < month1)
        {
            int result = 0;
            for (int i = month2; i < month1; i++)
                result += dayMount(i, year1);

            if (day1 == day2)                  // same days but different years  & months
                return temp + result;
            else if (day2 < day1)              // m2<m1 , d1>d2 , y1>y2
            {
                result += (day1 - day2);
                return temp + result;
            }
            else                               // m2<m1 , d1<d2 , y1>y2
            {
                result -= (day2 - day1);   
                return temp + result;
            }
        }
        else
        {
            int result = 0;
            for (int i = month1; i < month2; i++)
                result += dayMount(i, year1);

            if (day1 == day2)                 // same days, different years & months
                return temp - result;
            else if (day1 < day2)             // m1<m2 , d1<d2 , y1>y2
            {
                result += (day2 - day1);
                return temp - result;
            }
            else                              // m1<m2 , d1>d2 , y1>y2
            {
                result -= (day1 - day2);
                return temp - result;
            }
        }
    }
}

int main()
{
    int day1, day2, month1, month2, year1, year2, x;

    cout << "Enter date #1\n";
    cout << "Day : ";
    cin >> day1;
    cout << "Month : ";
    cin >> month1;
    cout << "Year : ";
    cin >> year1;
    x = dayMount(month1, year1);

    if (day1<1 || day1>x || month1 < 1 || month1 >12 || year1 < 1)
    {
        cout << "\nError";
        exit(0); 
    }

    cout << "\nEnter date #2\n";
    cout << "Day : ";
    cin >> day2;
    cout << "Month : ";
    cin >> month2;
    cout << "Year : ";
    cin >> year2;
    x = dayMount(month2, year2);

    if (day2<1 || day2>x || month2 < 1 || month2 >12 || year2 < 1)
    {
        cout << "\nError";
        exit(0);
    }

    cout << "\nDifference in two dates : " << differenceDays(day1, month1, year1, day2, month2, year2) << " days";

    return 0;
}