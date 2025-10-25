#include <iostream>
#include <vector>
#include <windows.h>
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
public:
    IncomeManager(int loggedUserId, string fileName) : TransactionManager(loggedUserId), incomesFile(fileName){
        incomes = incomesFile.readTransactionsFromfile(loggedUserId);
    };
    void addTransaction() override;
    void showTransactionsForDatesRange(const string &dateFrom, const string &dateTo) override;
    double calculateSumOfTransactionsAmount(const string &dateFrom, const string &dateTo) override;
};
