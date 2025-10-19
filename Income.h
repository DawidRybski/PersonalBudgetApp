#ifndef INCOME_H
#define INCOME_H

#include <iostream>
using namespace std;

class Income{
    int id;
    int userId;
    string date;
    string description;
    double amount;

public:
    int getId();
    int getUserId();
    string getDate();
    string getDescription();
    double getAmount();

    void setId(int newId);
    void setUserId(int newUserId);
    void setDate(string newDate);
    void setDescription(string newDescription);
    void setAmount(double newAmount);
};

#endif
