#include <iomanip>
#include "UserManager.h"

using namespace std;

class BudgetApp{

    UserManager userManager;

public:
    BudgetApp(string usersFileName) : userManager(usersFileName){};
    char selectAnOptionFromTheMainMenu();
    void registerUser();
    void userLogIn();
    void userLogOut();
    void changeLoggedUserPassword();
    bool isUserLogged();
    void logInTest();
};
