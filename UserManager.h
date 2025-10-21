#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include "User.h"
#include "Utils.h"
#include "UserFile.h"

using namespace std;

class UserManager{

    int loggedUserId = 0;
    vector <User> users;

    User provideNewUserData();
    int getNewUserId();
    bool doesLoginExist(string login);
    UserFile usersFile;

public:
    UserManager(string usersFileName) : usersFile(usersFileName){
        usersFile.readUsersFromFile(users);
    }
    void registerUser();
    void userLogIn();
    void userLogOut();
    void changeLoggedUserPassword();
    int getLoggedUserId();
    bool isUserLogged();
};
