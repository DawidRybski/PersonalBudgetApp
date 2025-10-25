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
    static bool isLeapYear(int year);
    static bool isValidDate(string date);
    static string provideValidDate();
    static string getlastDayOfPreviousMonth();
    static string getFirstDayOfCurrentMonth();
    static string getFirstDayOfPreviousMonth();

    template <typename T>
    static bool compareByDate(const T &a, const T &b){
        return a.getDate() < b.getDate();
    };
};

#endif
