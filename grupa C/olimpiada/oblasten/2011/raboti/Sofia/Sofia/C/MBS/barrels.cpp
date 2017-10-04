#include <iostream>
#include <cstring>
using namespace std;

int main(){
    long s, i;
    short int n, j;
    cin  >> s >> n;
    long t[n], arr[s+1];   //t-teglo, arr-1..s

    for(j = 0 ; j < n; j++) cin >> t[j];
    memset(arr, 0, (s+1)*sizeof(long));

    long curt;

    for(i = 0 ; i < s; i++){
        curt = arr[i] + 1; //cout << "ok\n";
        for(j = 0; j < n; j++){
            if(i+t[j]<=s && (arr[i+t[j]] == 0 || curt < arr[i+t[j]]))
                arr[i+t[j]] = curt;
        }
    }

    cout << arr[s] << endl;

    return 0;
}
