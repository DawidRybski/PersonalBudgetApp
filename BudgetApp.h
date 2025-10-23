#include <iomanip>
#include "UserManager.h"
#include "IncomeManager.h"
#include "ExpenseManager.h"

using namespace std;

class BudgetApp{

    UserManager userManager;
    IncomeManager *incomeManager;
    ExpenseManager *expenseManager;
//    const string INCOMES_FILE_NAME;

public:
    BudgetApp(string usersFileName) : userManager(usersFileName), incomeManager(nullptr), expenseManager(nullptr){};
    ~BudgetApp(){
        delete incomeManager;
        delete expenseManager;
    }
    char selectAnOptionFromTheMainMenu();
    void registerUser();
    void userLogIn();
    void userLogOut();
    void changeLoggedUserPassword();
    bool isUserLogged();
    void addTransaction(char option);
    void showTransactionsForDatesRange();
    void testDisplayExpenses();
};
