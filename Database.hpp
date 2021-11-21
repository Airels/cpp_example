//
// Created by yohan on 21/11/2021.
//

#ifndef LOGIN_DATABASE_H
#define LOGIN_DATABASE_H

#include "user.hpp"
#include <fstream>

class Database {
    string file;

public:
    Database(string filename);
    User * find(const string& username);
    bool insert(const string& username, const string& password);
};


#endif //LOGIN_DATABASE_H
