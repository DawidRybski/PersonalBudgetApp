#include "UserManager.h"

User UserManager::provideNewUserData(){
    User user;
    int userId;
    string userName;
    string userSurname;
    string userLogin;
    string userPassword;

    user.setId(getNewUserId());

    cout << "Podaj imie: ";
    userName = Utils::readLine();
    user.setName(userName);

    cout << "Podaj nazwisko: ";
    userSurname = Utils::readLine();
    user.setSurname(userSurname);

    do
    {
        cout << "Podaj login: ";
        userLogin = Utils::readLine();
        user.setLogin(userLogin);
    } while (doesLoginExist(user.getLogin()) == true);

    cout << "Podaj haslo: ";
    userPassword = Utils::readLine();
    user.setPassword(userPassword);

    return user;
}

int UserManager::getNewUserId(){
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager::doesLoginExist(string login){
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UserManager::registerUser(){
    User user = provideNewUserData();

    users.push_back(user);
//    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

void UserManager::userLogIn(){
    User user;
    string login = "", password = "";

    cout << endl << "Podaj login: ";
    login = Utils::readLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getLogin() == login)
        {
            for (int attempts = 3; attempts > 0; attempts--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << attempts << ": ";
                password = Utils::readLine();

                if (itr -> getPassword() == password)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    loggedUserId = itr -> getId();
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return;
}

int UserManager::getLoggedUserId(){
    return loggedUserId;
}

void UserManager::changeLoggedUserPassword(){
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    newPassword = Utils::readLine();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        if (itr -> getId() == loggedUserId)
        {
            itr -> setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
//    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}

void UserManager::userLogOut(){
    loggedUserId = 0;
}

bool UserManager::isUserLogged(){
    if (loggedUserId > 0)
        return true;
    else
        return false;
}

void UserManager::logInTest()
{
    for (auto& i:users){
        if (i.getId() == loggedUserId)
        {
            cout << "Dane uzytkownika po zalogowaniu: " << endl;
            cout << "Id: " << i.getId() << endl;
            cout << "Imie: " << i.getName() << endl;
            cout << "Nazwisko: " << i.getSurname() << endl;
            cout << "Login: " << i.getLogin() << endl;
            cout << "Haslo: " << i.getPassword() << endl << endl;
        }
    }
}

