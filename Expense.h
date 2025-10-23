#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>
using namespace std;

class Expense{
    int id;
    int userId;
    string date;
    string description;
    double amount;

public:
    int getId() const;
    int getUserId() const;
    string getDate() const;
    string getDescription() const;
    double getAmount() const;

    void setId(int newId);
    void setUserId(int newUserId);
    void setDate(string newDate);
    void setDescription(string newDescription);
    void setAmount(double newAmount);
};

#endif

