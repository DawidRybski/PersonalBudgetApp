#include <iostream>
#include <vector>
#include <windows.h>
#include <sstream>
#include "Expense.h"
#include "Utils.h"
#include "TransactionManager.h"

class ExpenseManager : public TransactionManager{
    vector <Expense> expenses;

    Expense provideDataOfTheNewExpense();

public:
    ExpenseManager(int loggedUserId) : TransactionManager(loggedUserId){
    };
    void addTransaction() override;
    void testDisplayExpenses();
};

