#include <iostream>
#include <vector>
#include "Markup.h"
#include "XmlFile.h"
#include "User.h"

class UserFile : public XmlFile{
public:
    UserFile(string userFileName) : XmlFile(userFileName){};
    void addUserToFile(User user);
    vector <User> readUsersFromFile(vector <User> &users);
    void changeUserInFile(vector <User> &users, User user, string newPassword);
};
