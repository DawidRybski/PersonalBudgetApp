#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include "User.h"
#include "Utils.h"

using namespace std;

class UserManager{

    int loggedUserId = 0;
    vector <User> users;

    User provideNewUserData();
    int getNewUserId();
    bool doesLoginExist(string login);

public:
//    UzytkownikMenedzer(string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami) {
//        uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
//    }
    void registerUser();
//    void wczytajUzytkownikowZPliku();
    void userLogIn();
    void userLogOut();
    void changeLoggedUserPassword();
    int getLoggedUserId();
    bool isUserLogged();
    void logInTest();
};
