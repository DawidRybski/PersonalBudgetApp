#include <iostream>
#include "BudgetApp.h"
#include "User.h"

using namespace std;

int main()
{
    BudgetApp budgetApp;
    User user;
    char choice;

    while (true)
    {
        if (!(budgetApp.isUserLogged()))
        {
            choice = budgetApp.selectAnOptionFromTheMainMenu();

            switch (choice)
            {
            case '1':
                budgetApp.registerUser();
                break;
            case '2':
                budgetApp.userLogIn();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        } else {
            budgetApp.logInTest();

            cout << "Zmiana hasla: ";
            budgetApp.changeLoggedUserPassword();

            budgetApp.userLogOut();
            system("pause");
        }
    }
}
