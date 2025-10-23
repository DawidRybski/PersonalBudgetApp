#include "Income.h"

int Income::getId() const{
    return id;
}

int Income::getUserId() const{
    return userId;
}

string Income::getDate() const{
    return date;
}

string Income::getDescription() const{
    return description;
}

double Income::getAmount() const{
    return amount;
}

void Income::setId(int newId){
    if (newId >= 0)
        id = newId;
}

void Income::setUserId(int newUserId){
    userId = newUserId;
}

void Income::setDate(string newDate){
    date = newDate;
}

void Income::setDescription(string newDescription){
    description = newDescription;
}

void Income::setAmount(double newAmount){
    amount = newAmount;
}
