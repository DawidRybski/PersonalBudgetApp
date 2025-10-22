#include "ExpenseManager.h"

void ExpenseManager::addTransaction(){
    Expense newExpense = provideDataOfTheNewExpense();
    expenses.push_back(newExpense);

    expensesFile.addTransactionToFile(newExpense);

    cout << endl << "Przychod zostal zarejestrowany" << endl << endl;
}

Expense ExpenseManager::provideDataOfTheNewExpense(){
    char character;
    Expense expense;

    expense.setId(expensesFile.getLastExpenseIdFromFile() + 1);
    expense.setUserId(getLoggedUserId());

    cout << "Czy wydatek jest z dzisiejszego dnia? (wprowadz 't' aby potwierdzic lub inny znak jezeli przychod jest z innego dnia):";
    character = Utils::readChar();

    if (character == 't')
        expense.setDate(Utils::getCurrentDate());
    else {
        cout << "Wprowadz date wydatku w formacie YYYY-MM-DD w zakresie od 2000-01-01 do " << Utils::getCurrentDate() << endl;
        expense.setDate(Utils::provideValidDate());
    }

    cout << "Podaj czego dotyczy wydatek: ";
    expense.setDescription(Utils::readLine());

    cout << "Podaj kwote wydatku: ";
    expense.setAmount(Utils::readDouble());

    return expense;
}

void ExpenseManager::testDisplayExpenses(){
    for (auto& e : expenses){
        cout << e.getId() << endl;
        cout << e.getUserId() << endl;
        cout << e.getDate() << endl;
        cout << e.getDescription() << endl;
        cout << e.getAmount() << endl;
    }
}
