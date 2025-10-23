#include "ExpensesFile.h"

void ExpensesFile::addTransactionToFile(Expense &expense){
    CMarkup xml;

    bool fileExists = xml.Load(getFileName());

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("ExpenseId", expense.getId());
    xml.AddElem("UserId", expense.getUserId());
    xml.AddElem("Date", expense.getDate());
    xml.AddElem("Description", expense.getDescription());

    stringstream ss;
    ss << fixed << setprecision(2) << expense.getAmount();
    xml.AddElem("Amount", ss.str());

    xml.Save(getFileName());
}

vector <Expense> ExpensesFile::readTransactionsFromfile(int loggedUserId){
    CMarkup xml;
    Expense expense;

    bool fileExists = xml.Load(getFileName());

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
    }

    if (xml.FindElem("Expenses")) {
        xml.IntoElem();

        while (xml.FindElem("Expense")) {
            xml.IntoElem();

            xml.FindElem("ExpenseId");
            expense.setId(atoi(xml.GetData().c_str()));
            lastExpenseId = atoi(xml.GetData().c_str());

            xml.FindElem("UserId");
            expense.setUserId(atoi(xml.GetData().c_str()));

            xml.FindElem("Date");
            expense.setDate(xml.GetData());

            xml.FindElem("Description");
            expense.setDescription(xml.GetData());

            xml.FindElem("Amount");
            expense.setAmount(atof(xml.GetData().c_str()));

            if (expense.getUserId() == loggedUserId) {
                expenses.push_back(expense);
            }

            xml.OutOfElem();
        }
        xml.OutOfElem();
    }

    return expenses;
}

int ExpensesFile::getLastExpenseIdFromFile(){
    int lastExpenseId = 0;
    CMarkup xml;

    bool fileExists = xml.Load(getFileName());

    if (!fileExists) {
        return lastExpenseId;
    }

    if (xml.FindElem("Expenses")){
        xml.IntoElem();

        while (xml.FindElem("Expense")){
            xml.IntoElem();

            xml.FindElem("ExpenseId");
            lastExpenseId = atoi(xml.GetData().c_str());
            xml.OutOfElem();
        }
        xml.OutOfElem();
    }

    return lastExpenseId;
}
