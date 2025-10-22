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

void BudgetApp::testDisplayIncomes(){
    incomeManager->testDisplayIncomes();
    system("pause");
}

void BudgetApp::testDisplayExpenses(){
    expenseManager->testDisplayExpenses();
    system("pause");
}
