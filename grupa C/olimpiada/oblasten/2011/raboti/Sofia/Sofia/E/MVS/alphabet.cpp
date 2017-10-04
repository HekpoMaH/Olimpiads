#include <iostream>
using namespace std;

int main(){
    long long num;
    bool has = false;
    char now;
    long long trys;
    long long alphabet;
    char movies[20];
    cin >> alphabet;
    cin >> trys;
    for(long long count = 0; count < trys; count ++){
        cin >> movies[count];
        for( ; now != '.' ; ){
            cin >> now;
        }
        now = '!';
        if((movies[count] == 'a' + (alphabet - 1) || movies[count] == 'A' + (alphabet - 1)) && has == false){
            has = true;
            num = count;
        }
    }
    if(has == true){
        cout << "win " << num + 1 << endl;
    }else{
        cout << "lose" << endl;
    }
    return 0;
}
