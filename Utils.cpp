#include "Utils.h"

string Utils::readLine(){
    string entry = "";
    getline(cin, entry);
    return entry;
}

char Utils::readChar(){
    string entry = "";
    char character  = {0};

    while (true)
    {
        getline(cin, entry);

        if (entry.length() == 1)
        {
            character = entry[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return character;
}

int Utils::readInteger(){
    string entry = "";
    int number = 0;

    while (true)
    {
        getline(cin, entry);

        stringstream myStream(entry);
        if (myStream >> number)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return number;
}

double Utils::readDouble(){
    string entry = "";
    double number = 0.0;

    while (true)
    {
        getline(cin, entry);

        replace(entry.begin(), entry.end(), ',', '.');

        stringstream myStream(entry);
        if (myStream >> number)
        {
            char excessCharacters;
            if (!(myStream >> excessCharacters))
                break;
        }

        cout << "To nie jest poprawna liczba zmiennoprzecinkowa. Wpisz ponownie: " << endl;
    }

    return number;
}

string Utils::addZeroToSingleDigitNumber(int value){
    if (value < 10) {
        return "0" + to_string(value);
    } else {
        return to_string(value);
    }
}

string Utils::getCurrentDate(){
    time_t now = time(nullptr);

    tm localTime{};
    #ifdef _WIN32
    localtime_s(&localTime, &now);
    #else
    localtime_r(&now, &localTime);
    #endif

    string year  = to_string(localTime.tm_year + 1900);
    string month = addZeroToSingleDigitNumber(localTime.tm_mon + 1);
    string day   = addZeroToSingleDigitNumber(localTime.tm_mday);

    return year + "-" + month + "-" + day;
}

bool Utils::isLeapYear(int year){
    return (year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0);
}

bool Utils::isValidDate(string date){
    if (date.size() != 10 || date[4] != '-' || date[7] != '-') return false;

    int year, month, day;
    char dash1, dash2;
    istringstream iss(date);
    if (!(iss >> year >> dash1 >> month >> dash2 >> day)) return false;

    if (dash1 != '-' || dash2 != '-') return false;

    if (month < 1 || month > 12) return false;

    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && isLeapYear(year)) daysInMonth[1] = 29;

    if (day < 1 || day > daysInMonth[month - 1]) return false;

    if (!(date >= "2000-01-01" && date <= getCurrentDate())) return false;

    return true;
}

string Utils::provideValidDate() {
    string providedDate = "";

    while (true) {
        providedDate = readLine();

        if (isValidDate(providedDate))
            break;
        else
            cout << "Podana data jest nieprawidlowa. Prosze podac date w formacie YYYY-MM-DD w zakresie od 2000-01-01 do " << getCurrentDate() << endl;
    }

    return providedDate;
}

string Utils::getlastDayOfMonth(int year, int month){
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && isLeapYear(year)) daysInMonth[1] = 29;

    stringstream ss;
    ss << year << "-" << addZeroToSingleDigitNumber(month) << "-" << daysInMonth[month-1];
    return ss.str();
}

string Utils::getFirstDayOfMonth(int year, int month){
    stringstream ss;
    ss << year << "-" << addZeroToSingleDigitNumber(month) << "-01";
    return ss.str();
}
