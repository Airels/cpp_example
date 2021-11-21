#include <iostream>
#include "user.hpp"
#include "Database.hpp"

using namespace std;

void signup(Database db) {
    string username;
    string password;

    cout << "Username? ";
    cin >> username;

    User *user = db.find(username);
    if (user != nullptr) {
        delete user;
        cout << "Username already exist. Abort." << endl;
        return;
    }

    cout << "Password? ";
    cin >> password;

    if (db.insert(username, password))
        cout << "Registration successful." << endl;
    else
        cout << "Error occurred on registration." << endl;
}

void login(Database db) {
    string username;
    string password;

    cout << "Username? ";
    cin >> username;

    cout << "Password? ";
    cin >> password;

    User *user = db.find(username);
    if (user == nullptr) {
        cout << "Invalid credentials." << endl;
        return;
    }

    if (user->getPassword() == password)
        cout << "Authentication successful." << endl;
    else
        cout << "Invalid credentials." << endl;

    delete user;
}

int main() {

    Database db = Database("db.txt");

    cout << "Choice :" << endl;
    cout << "1: Login" << endl;
    cout << "2: Register" << endl;

    string choice;

    cin >> choice;

    if (choice == "1")
        login(db);
    else if (choice == "2")
        signup(db);
    else
        cout << "Invalid choice." << endl;

    return 0;
}
