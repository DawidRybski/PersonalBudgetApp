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

bool BudgetApp::isUserLogged(){
    userManager.isUserLogged();
}

void BudgetApp::addTransaction(char option){
    if (option == '1')
    {
        incomeManager->addTransaction();
    } else {
        expenseManager->addTransaction();
    }
    system("pause");
}

//void BudgetApp::showTransactionsForDatesRange(){
//    incomeManager->showTransactionsForDatesRange("2000-01-01", "2025-10-23");
//    expenseManager->showTransactionsForDatesRange("2000-01-01", "2025-10-23");
//}
//
//void BudgetApp::showBalanceForDatesRange(){
//    cout << "Przychody: " << incomeManager->calculateSumOfTransactionsAmount("2000-01-01", "2025-10-23") << endl;
//    cout << "Wydatki: " << expenseManager->calculateSumOfTransactionsAmount("2000-01-01", "2025-10-23") << endl;
//    system("pause");
//}

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
