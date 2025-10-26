#include <iostream>
#include "BudgetApp.h"
#include "User.h"

using namespace std;

int main()
{
    BudgetApp budgetApp("users.xml");
    User user;
    char choice;

    while (true){
        if (!(budgetApp.isUserLogged())){
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
            choice = budgetApp.selectAnOptionFromTheUserMenu();

            switch (choice){
            case '1':
                budgetApp.addTransaction(choice);
                break;
            case '2':
                budgetApp.addTransaction(choice);
                break;
            case '3':
                budgetApp.showTransactionsAndBalanceForCurrentMonth();
                break;
            case '4':
                budgetApp.showTransactionsAndBalanceForPreviousMonth();
                break;
            case '5':
                budgetApp.showTransactionsAndBalanceForCustomDatesRange();
                break;
            case '6':
                budgetApp.changeLoggedUserPassword();
                break;
            case '7':
                budgetApp.userLogOut();
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
    }
}
