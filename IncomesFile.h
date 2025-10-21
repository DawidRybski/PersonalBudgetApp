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
public:
    IncomesFile(string incomesFileName) : TransactionsFile(incomesFileName){};
    void addTransactionToFile(Income &income) override;
};

#endif
