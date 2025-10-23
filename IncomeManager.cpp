#include "IncomeManager.h"

void IncomeManager::addTransaction(){
    Income newIncome = provideDataOfTheNewIncome();
    incomes.push_back(newIncome);

    incomesFile.addTransactionToFile(newIncome);

    cout << endl << "Przychod zostal zarejestrowany" << endl << endl;
}

Income IncomeManager::provideDataOfTheNewIncome(){
    char character;
    Income income;

    income.setId(incomesFile.getLastIncomeIdFromFile() + 1);
    income.setUserId(getLoggedUserId());

    cout << "Czy przychod jest z dzisiejszego dnia? (wprowadz 't' aby potwierdzic lub inny znak jezeli przychod jest z innego dnia):";
    character = Utils::readChar();

    if (character == 't')
        income.setDate(Utils::getCurrentDate());
    else {
        cout << "Wprowadz date przychodu w formacie YYYY-MM-DD w zakresie od 2000-01-01 do " << Utils::getCurrentDate() << endl;
        income.setDate(Utils::provideValidDate());
    }

    cout << "Podaj czego dotyczy przychod: ";
    income.setDescription(Utils::readLine());

    cout << "Podaj kwote przychodu: ";
    income.setAmount(Utils::readDouble());

    return income;
}

void IncomeManager::showTransactionsForDatesRange(const string &dateFrom, const string &dateTo){
    sort(incomes.begin(), incomes.end(), Utils::compareByDate<Income>);
    cout << endl << "=======PRZYCHODY======= " << endl;
    for (const auto& i : incomes){
        if ((i.getDate() >= dateFrom) && (i.getDate() <= dateTo)){
            cout << "Data: " << i.getDate() << endl
            << "Opis: " << i.getDescription() << endl
            << "Kwota przychodu: " << i.getAmount() << endl << endl;
        }
    }
}
