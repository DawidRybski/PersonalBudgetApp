#include "BudgetApp.h"

void BudgetApp::registerUser(){
    userManager.registerUser();
}

void BudgetApp::userLogIn(){
    userManager.userLogIn();
    if(userManager.isUserLogged()){
        incomeManager = new IncomeManager(userManager.getLoggedUserId(), "incomes.xml");
        expenseManager = new ExpenseManager(userManager.getLoggedUserId(), "expenses.xml");
    }
}

void BudgetApp::userLogOut(){
    userManager.userLogOut();
    delete incomeManager;
    incomeManager = nullptr;
    delete expenseManager;
    expenseManager = nullptr;
}

void BudgetApp::changeLoggedUserPassword(){
    userManager.changeLoggedUserPassword();
}

char BudgetApp::selectAnOptionFromTheMainMenu(){
    char choice;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = Utils::readChar();

    return choice;
}

char BudgetApp::selectAnOptionFromTheUserMenu(){
    char choice;

    system("cls");
    cout << " >>> MENU  UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Pokaz transakcje i bilans z biezacego miesiaca" << endl;
    cout << "4. Pokaz transakcje i bilans z poprzedniego miesiaca" << endl;
    cout << "5. Pokaz transakcje i bilans z wybranego zakresu dat" << endl;
    cout << "6. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = Utils::readChar();

    return choice;
}

bool BudgetApp::isUserLogged(){
    userManager.isUserLogged();
}

void BudgetApp::addTransaction(char option){
    if (option == '1')
    {
        incomeManager->addTransaction();
    } else if (option == '2'){
        expenseManager->addTransaction();
    }
    system("pause");
}

void BudgetApp::showTransactionsAndBalanceForCurrentMonth(){
    cout << "Transakcje z biezacego miesiaca: " << endl;
    vector <TransactionManager*> managers = {incomeManager, expenseManager};

    string firstDayOfCurrentMonth = Utils::getFirstDayOfCurrentMonth();
    string currentDate = Utils::getCurrentDate();

    for (TransactionManager* manager : managers){
        manager->showTransactionsForDatesRange(firstDayOfCurrentMonth, currentDate);
    }

    double totalIncome = incomeManager->calculateSumOfTransactionsAmount(firstDayOfCurrentMonth, currentDate);
    double totalExpense = expenseManager->calculateSumOfTransactionsAmount(firstDayOfCurrentMonth, currentDate);
    double totalBalance = totalIncome - totalExpense;

    cout << "Bilans z biezacego miesiaca: " << totalBalance << endl;
    system("pause");
}

void BudgetApp::showTransactionsAndBalanceForPreviousMonth(){
    cout << "Transakcje z poprzedniego miesiaca: " << endl;
    vector <TransactionManager*> managers = {incomeManager, expenseManager};

    string firstDayOfPreviousMonth = Utils::getFirstDayOfPreviousMonth();
    string lastDayOfPreviousMonth = Utils::getlastDayOfPreviousMonth();

    for (TransactionManager* manager : managers){
        manager->showTransactionsForDatesRange(firstDayOfPreviousMonth, lastDayOfPreviousMonth);
    }

    double totalIncome = incomeManager->calculateSumOfTransactionsAmount(firstDayOfPreviousMonth, lastDayOfPreviousMonth);
    double totalExpense = expenseManager->calculateSumOfTransactionsAmount(firstDayOfPreviousMonth, lastDayOfPreviousMonth);
    double totalBalance = totalIncome - totalExpense;

    cout << "Bilans z poprzedniego miesiaca: " << totalBalance << endl;
    system("pause");
}

void BudgetApp::showTransactionsAndBalanceForCustomDatesRange(){
    cout << "Wprowadz date poczatkowa: ";
    string firstDayOfCustomDate = Utils::provideValidDate();
    cout << "Wprowadz date koncowa: ";
    string lastDayOfCustomDate = Utils::provideValidDate();

    cout << "Transakcje z wybranego zakresu dat: " << endl;
    vector <TransactionManager*> managers = {incomeManager, expenseManager};

    for (TransactionManager* manager : managers){
        manager->showTransactionsForDatesRange(firstDayOfCustomDate, lastDayOfCustomDate);
    }

    double totalIncome = incomeManager->calculateSumOfTransactionsAmount(firstDayOfCustomDate, lastDayOfCustomDate);
    double totalExpense = expenseManager->calculateSumOfTransactionsAmount(firstDayOfCustomDate, lastDayOfCustomDate);
    double totalBalance = totalIncome - totalExpense;

    cout << "Bilans z wybranego zakresu dat: " << totalBalance << endl;
    system("pause");
}
