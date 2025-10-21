#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H
#include "XmlFile.h"

class TransactionManager{
    const int LOGGED_USER_ID;

public:
    TransactionManager(int loggedUserId) : LOGGED_USER_ID(loggedUserId) {}
    virtual ~TransactionManager() = default;
    virtual void addTransaction() = 0;
    int getLoggedUserId() const { return LOGGED_USER_ID; }
};

#endif
