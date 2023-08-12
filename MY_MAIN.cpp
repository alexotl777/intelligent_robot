#include <iostream>
#include <stdlib.h> // нужен для вызова функций rand(), srand()
#include <time.h> // нужен для вызова функции time()
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
int random(int a, int b){

    // Установить генератор случайных чисел
    srand(time(NULL));

    // Получить случайное число - формула
    int num = a + rand() % (b - a + 1);

    return num;

}
void game1(){
    int a,b;
    cout << "Enter start and finish" << endl;
    cin >> a >> b;
    if(a==b){
        cout << "ERROR: start = finish" << endl;
    }
    else{
        int x = random(a, b);
        cout << "Try to guess number from " << a << " to " << b << endl;
        int ans;
        cin >> ans;
        int att = 1;
        while(true){
            if(ans > x){
                cout << "The hidden number is less! Try again" << endl; 
            }
            else if (ans < x){
                cout << "The hidden number is greater! Try again" << endl;
            }
            else{
                cout << "Well done! You guessed" << endl;
                cout << "Attemps: " << att;
                break;
            }
            att++;
            cin >> ans;
        }
    }

}
void game2(){
    string line;

    ifstream in("cities_en.txt"); // окрываем файл с городами для чтения

    vector<string> all_c;
    if (in.is_open())
    {
        while (getline(in, line))
        {
            transform(line.begin(), line.end(), line.begin(), ::tolower);
            all_c.insert(all_c.end(), line);
        }
    }
    in.close();     // закрываем файл
    
    cout << "Start first" << endl << "If you do not know, write END" << endl;
    string city;

    cin >> city;
    
    int f=0, h=0;
    while(f==0 && city != "END" && city != "end"){
        transform(city.begin(), city.end(), city.begin(), ::tolower);
        char letter = city[city.size()-1];
        for(int i = 0; i<all_c.size(); i++){
            
            
            if(all_c[i][0] == letter){
                transform(all_c[i].begin(), all_c[i].end(), all_c[i].begin(), ::toupper);
                cout << "I know! "<<all_c[i] << endl << "Next..." << endl;
                h=1;
                
                break;
            }
        }
        if(h == 0){
            cout << "I do not know... You won(" << endl;
            f=1;
        }
        else{
            cin >> city;
            if(city == "end" || city == "END"){
                cout << "Hahaha, I won" << endl;
            }
        }
        

    }

    cout << "End of game" << endl;



}

void game3(){
    string word = "golova";
    cout << "Total letters " << 6 << endl;
    char s;
    int ind=0, tries=0;
    while(true && tries!=15 && ind!=6){
        cout << "Enter letter" << endl;
        cin >> s;
        if(word.find(s)!=-1){
            ind++;
            cout << "You are right! Letters left " << 6-ind << endl;

        }
        else{
            cout << "NO! Try again" << endl << "Tries left " << 15 - tries << endl << endl;
            tries++;

        }
    }
    cout << "End of game" << endl;
}
struct User {
    string login;
    string password;
};

vector<User> users;
void registerUser() {
    User user;
    cout << "Enter login: ";
    system("python my_spee.py");
    cin >> user.login;
    cout << "Enter password: ";
    system("python my_spee.py");
    cin >> user.password;
    users.push_back(user);
    ofstream outfile("users.txt", ios::app);
    outfile << user.login << " " << user.password << endl;
    outfile.close();
}

bool loginUser() {
    string login, password;
    cout << "Enter login: ";
    system("python my_spee.py");
    cin >> login;
    cout << "Enter password: ";
    system("python my_spee.py");
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
                exit(0);
                break;
            default:
                cout << "Wrong choice" << endl;
                break;
        }
    } while (choice != 3);
    int num_game;
    cout << "choose game (1, 2 or 3)\n";
    cin >> num_game;
    if (num_game == 1){
        game1();
    }
    else if (num_game == 2){
        game2();
    }
    else if (num_game == 3){
        game3();
    }
    else{
        cout << "There is no such game\n";
    }
    cout << "\nTo make a photo? Y/n\n";
    string yn;
    cin >> yn;
    if(yn=="Y"){
        system("my_campy.py");
    }
    cout << "\nBye!\n";
    return 0;
}
