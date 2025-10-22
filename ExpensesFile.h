#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include "TransactionsFile.h"
#include "Expense.h"
#include "Markup.h"

class ExpensesFile : public TransactionsFile<Expense>{
    vector <Expense> expenses;
    int lastExpenseId;

public:
    ExpensesFile(string expensesFileName) : TransactionsFile(expensesFileName){
        lastExpenseId = 0;
    };
    void addTransactionToFile(Expense &expense) override;
    vector <Expense> readTransactionsFromfile(int loggedUserId) override;
    int getLastExpenseIdFromFile();
};

#endif
