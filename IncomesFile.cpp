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
