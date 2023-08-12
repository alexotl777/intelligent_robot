#include <iostream>
#include <string>

using namespace std;

int main(){
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
