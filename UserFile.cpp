#include "UserFile.h"

void UserFile::addUserToFile(User user) {
    CMarkup xml;

    bool fileExists = xml.Load(getFileName());

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.getId());
    xml.AddElem("Name", user.getName());
    xml.AddElem("Surname", user.getSurname());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());
    xml.Save(getFileName());
}

void UserFile::readUsersFromFile(vector <User> &users){
    CMarkup xml;
    User user;

    if (!xml.Load(getFileName())) {
        cout << "Nie udało się wczytać pliku XML!" << endl;
    }

    if (xml.FindElem("Users")) {
        xml.IntoElem();

        while (xml.FindElem("User")) {
            xml.IntoElem();

            xml.FindElem("UserId");
            user.setId(atoi(xml.GetData().c_str()));

            xml.FindElem("Name");
            user.setName(xml.GetData());

            xml.FindElem("Surname");
            user.setSurname(xml.GetData());

            xml.FindElem("Login");
            user.setLogin(xml.GetData());

            xml.FindElem("Password");
            user.setPassword(xml.GetData());

            users.push_back(user);

            xml.OutOfElem();
        }

        xml.OutOfElem();
    }
}

void UserFile::changeUserInFile(vector <User> &users, User user, string newPassword){
    CMarkup xml;

    if (!xml.Load(getFileName())) {
        cout << "Nie udało się wczytać pliku XML!" << endl;
        return;
    }

    if (xml.FindElem("Users")) {
        xml.IntoElem();

        while (xml.FindElem("User")) {
            xml.IntoElem();

            if (xml.FindElem("UserId")) {
                int id = stoi(xml.GetData());
                if (id == user.getId()) {
                    if (xml.FindElem("Password")) {
                        xml.SetData(newPassword);
                    }
                }
            }

            xml.OutOfElem();
        }

        xml.OutOfElem();
    }

    xml.Save(getFileName());
}
