//угадай число
#include <iostream>
#include <stdlib.h> // нужен для вызова функций rand(), srand()
#include <time.h> // нужен для вызова функции time()

using namespace std;
int random(int a, int b){

    // Установить генератор случайных чисел
    srand(time(NULL));

    // Получить случайное число - формула
    int num = a + rand() % (b - a + 1);

    return num;

}



int main(){
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

    return 0;
}