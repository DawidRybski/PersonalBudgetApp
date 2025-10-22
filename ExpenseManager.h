#include <iostream>
#include <vector>
#include <windows.h>
#include <sstream>
#include "Expense.h"
#include "Utils.h"
#include "TransactionManager.h"
#include "ExpensesFile.h"

class ExpenseManager : public TransactionManager{
    vector <Expense> expenses;
    ExpensesFile expensesFile;

    Expense provideDataOfTheNewExpense();

public:
    ExpenseManager(int loggedUserId, string fileName) : TransactionManager(loggedUserId), expensesFile(fileName){
        expenses = expensesFile.readTransactionsFromfile(loggedUserId);
    };
    void addTransaction() override;
    void testDisplayExpenses();
};

