#include "IncomeManager.h"

void IncomeManager::addTransaction(){
    Income income = provideDataOfTheNewIncome();
    incomes.push_back(income);

    incomesFile.addTransactionToFile(income);

    cout << endl << "Przychod zostal zarejestrowany" << endl << endl;
    system("pause");
}

Income IncomeManager::provideDataOfTheNewIncome(){
    char character;
    Income income;

    income.setId(getNewIncomeId());
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

int IncomeManager::getNewIncomeId(){
    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().getId() + 1;
}

void IncomeManager::testDisplayIncomes(){
    for (auto& i : incomes){
        cout << i.getId() << endl;
        cout << i.getUserId() << endl;
        cout << i.getDate() << endl;
        cout << i.getDescription() << endl;
        cout << i.getAmount() << endl;
    }
}
