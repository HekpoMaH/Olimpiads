#include <iostream>
using namespace std;

int main(){
    long long first, second;
    cin >> first;
    cin >> second;
    for(long long count = 1; ; count ++){
        if(first * second * count % (first + second) == 0){
            cout << 2 * first * second * count / (first + second) << endl;
            break;
        }
    }
    return 0;
}
