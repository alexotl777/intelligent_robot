#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>



using namespace std;

int main(){
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


    return 0;
}