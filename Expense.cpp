#include "Expense.h"

int Expense::getId(){
    return id;
}

int Expense::getUserId(){
    return userId;
}

string Expense::getDate(){
    return date;
}

string Expense::getDescription(){
    return description;
}

double Expense::getAmount(){
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
