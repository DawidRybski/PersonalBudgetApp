#include "IncomesFile.h"

void IncomesFile::addTransactionToFile(Income &income){
    CMarkup xml;

    bool fileExists = xml.Load(getFileName());

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("IncomeId", income.getId());
    xml.AddElem("UserId", income.getUserId());
    xml.AddElem("Date", income.getDate());
    xml.AddElem("Description", income.getDescription());

    stringstream ss;
    ss << fixed << setprecision(2) << income.getAmount();
    xml.AddElem("Amount", ss.str());

    xml.Save(getFileName());
}

vector <Income> IncomesFile::readTransactionsFromfile(int loggedUserId){
    CMarkup xml;
    Income income;

    bool fileExists = xml.Load(getFileName());

    if (!fileExists) {
        cout << "Nie udalo sie wczytac pliku XML!" << endl;
        return incomes;
    }

    if (xml.FindElem("Incomes")) {
        xml.IntoElem();

        while (xml.FindElem("Income")) {
            xml.IntoElem();

            xml.FindElem("IncomeId");
            income.setId(atoi(xml.GetData().c_str()));
            lastIncomeId = atoi(xml.GetData().c_str());

            xml.FindElem("UserId");
            income.setUserId(atoi(xml.GetData().c_str()));

            xml.FindElem("Date");
            income.setDate(xml.GetData());

            xml.FindElem("Description");
            income.setDescription(xml.GetData());

            xml.FindElem("Amount");
            income.setAmount(atof(xml.GetData().c_str()));

            if (income.getUserId() == loggedUserId) {
                incomes.push_back(income);
            }

            xml.OutOfElem();
        }
        xml.OutOfElem();
    }

    return incomes;
}

int IncomesFile::getLastIncomeIdFromFile(){
    int lastIncomeId = 0;
    CMarkup xml;

    bool fileExists = xml.Load(getFileName());

    if (!fileExists) {
        cout << "Nie udalo sie wczytac pliku XML!" << endl;
        return lastIncomeId;
    }

    if (xml.FindElem("Incomes")){
        xml.IntoElem();

        while (xml.FindElem("Income")){
            xml.IntoElem();

            xml.FindElem("IncomeId");
            lastIncomeId = atoi(xml.GetData().c_str());
            xml.OutOfElem();
        }
        xml.OutOfElem();
    }

    return lastIncomeId;
}

