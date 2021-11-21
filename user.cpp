#include "user.hpp"

using namespace std;

User::User(string username, string password) {
    this->username = username;
    this->password = password;
}

string User::getUsername() {
    return username;
}

string User::getPassword() {
    return password;
}

bool User::login(const string& passwd) {
    return (password == passwd);
}

