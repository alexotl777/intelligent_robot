#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct User {
    string login;
    string password;
};

vector<User> users;

void registerUser() {
    User user;
    cout << "Enter login: ";
    cin >> user.login;
    cout << "Enter password: ";
    cin >> user.password;
    users.push_back(user);
    ofstream outfile("users.txt", ios::app);
    outfile << user.login << " " << user.password << endl;
    outfile.close();
}

bool loginUser() {
    string login, password;
    cout << "Enter login: ";
    cin >> login;
    cout << "Enter password: ";
    cin >> password;
    for (const auto& user : users) {
        if (user.login == login && user.password == password) {
            return true;
        }
    }
    return false;
}

int main() {
    setlocale(LC_ALL,"utf-8");
    ifstream infile("users.txt");
    string login, password;
    while (infile >> login >> password) {
        users.push_back({login, password});
    }
    infile.close();
    int choice;
    do {
        cout << "1. Registration" << endl;
        cout << "2. Entrance" << endl;
        cout << "3. Exit" << endl;
        cout << "Choose an action: ";
        cin >> choice;
        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                if (loginUser()) {
                    cout << "Login Successful" << endl;
                } else {
                    cout << "Wrong login or password" << endl;
                }
                choice = 3;
                break;
            case 3:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Wrong choice" << endl;
                break;
        }
    } while (choice != 3);
    return 0;
}