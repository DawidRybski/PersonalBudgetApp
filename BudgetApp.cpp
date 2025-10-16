#include "BudgetApp.h"

void BudgetApp::registerUser(){
    userManager.registerUser();
}

void BudgetApp::userLogIn(){
    userManager.userLogIn();
}

void BudgetApp::userLogOut(){
    userManager.userLogOut();
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

void BudgetApp::logInTest(){
    userManager.logInTest();
}
