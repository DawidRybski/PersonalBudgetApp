#include <iomanip>
#include "UserManager.h"
#include "TransactionManager.h"
#include "IncomeManager.h"

using namespace std;

class BudgetApp{

    UserManager userManager;
    IncomeManager *incomeManager;
//    const string INCOMES_FILE_NAME;

public:
    BudgetApp(string usersFileName) : userManager(usersFileName), incomeManager(nullptr){};
    ~BudgetApp(){
        delete incomeManager;
    }
    char selectAnOptionFromTheMainMenu();
    void registerUser();
    void userLogIn();
    void userLogOut();
    void changeLoggedUserPassword();
    bool isUserLogged();
    void logInTest();
    void addTransaction(char option);
};
