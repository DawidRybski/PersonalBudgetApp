#ifndef TRANSACTIONSFILE_H
#define TRANSACTIONSFILE_H
#include "XmlFile.h"

template <typename T>
class TransactionsFile : public XmlFile{

public:
    TransactionsFile(string transactionFileName) : XmlFile(transactionFileName){};
    virtual void addTransactionToFile(T &transaction) = 0;
};


#endif
