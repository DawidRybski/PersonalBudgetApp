#include "Expense.h"

int Expense::getId() const{
    return id;
}

int Expense::getUserId() const{
    return userId;
}

string Expense::getDate() const{
    return date;
}

string Expense::getDescription() const{
    return description;
}

double Expense::getAmount() const{
    return amount;
}

void Expense::setId(int newId){
    if (newId >= 0)
        id = newId;
}

void Expense::setUserId(int newUserId){
    userId = newUserId;
}

void Expense::setDate(string newDate){
    date = newDate;
}

void Expense::setDescription(string newDescription){
    description = newDescription;
}

void Expense::setAmount(double newAmount){
    amount = newAmount;
}
