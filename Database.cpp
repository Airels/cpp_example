//
// Created by yohan on 21/11/2021.
//

#include <iostream>
#include "Database.hpp"

Database::Database(string filename) {
    file = filename;

    ifstream File(file);
    string line;

    getline(File, line);

    cout << (line != "=DB=") << endl;

    if (line != "=DB=") {
        File.clear();

        File.close();

        ofstream FileIn(file);

        FileIn << "=DB=" << endl;

        FileIn.close();
    } else {
        File.close();
    }
}

User * Database::find(const string& username) {

    ifstream File(file);
    string line;

    while (getline(File, line)) {
        if (line.find(username) != string::npos) {
            string u = line.substr(0, line.find(';'));
            line.erase(0, line.find(';') + 1); // +1 for length of DELIMITER

            return new User(u, line);
        }
    }

    File.close();

    return nullptr;
}

bool Database::insert(const string& username, const string& password) {
    User *user = find(username);

    if (user != nullptr) {
        delete user;
        return false;
    }

    ofstream outfile;
    outfile.open(file, ios_base::app);

    outfile << username << ';' << password << endl;

    outfile.close();

    return true;
}
