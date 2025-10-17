#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <ctime>
using namespace std;

class Utils
{
public:
    static string readLine();
    static char readChar();
    static int readInteger();
    static double readDouble();
    static string addZeroToSingleDigitNumber(int value);
    static string getCurrentDate();
    bool isLeapYear(int year);
    bool isValidDate(string date);
    string provideValidDate();
    string getlastDayOfMonth(int year, int month);
    string getFirstDayOfMonth(int year, int month);
};

#endif
