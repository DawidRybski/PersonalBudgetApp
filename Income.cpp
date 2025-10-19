#include "Income.h"

int Income::getId(){
    return id;
}

int Income::getUserId(){
    return userId;
}

string Income::getDate(){
    return date;
}

string Income::getDescription(){
    return description;
}

double Income::getAmount(){
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
