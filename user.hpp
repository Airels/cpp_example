#ifndef USER_HPP
#define USER_HPP

#include <string>

using namespace std;

class User {
    string username, password;

public:
    User(string username, string password);
    string getUsername();
    string getPassword();
    bool login(const string& password);
};

#endif
