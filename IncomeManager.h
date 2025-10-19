#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include "Income.h"
#include "Utils.h"
#include "TransactionManager.h"

class IncomeManager : public TransactionManager{
    vector <Income> incomes;

    Income provideDataOfTheNewIncome();
    int getNewIncomeId();

public:
    IncomeManager(int loggedUserId) : TransactionManager(loggedUserId){};
    void addTransaction() override;
    void testDisplayIncomes();
};
