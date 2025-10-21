#ifndef INCOMESFILE_H
#define INCOMESFILE_H
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include "TransactionsFile.h"
#include "Income.h"
#include "Markup.h"

class IncomesFile : public TransactionsFile<Income>{
    vector <Income> incomes;
    int lastIncomeId;

public:
    IncomesFile(string incomesFileName) : TransactionsFile(incomesFileName){
        lastIncomeId = 0;
    };
    void addTransactionToFile(Income &income) override;
    vector <Income> readTransactionsFromfile(int loggedUserId) override;
    int getLastIncomeIdFromFile();
};

#endif
