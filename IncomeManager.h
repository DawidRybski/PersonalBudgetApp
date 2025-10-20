#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include "Income.h"
#include "Utils.h"
#include "TransactionManager.h"
#include "TransactionsFile.h"
#include "IncomesFile.h"

class IncomeManager : public TransactionManager{
    vector <Income> incomes;
    IncomesFile incomesFile;

    Income provideDataOfTheNewIncome();
    int getNewIncomeId();

public:
    IncomeManager(int loggedUserId, string fileName) : TransactionManager(loggedUserId), incomesFile(fileName){};
    void addTransaction() override;
    void testDisplayIncomes();
};
