#include <iostream>
#include <cstring>
using namespace std;

int main(){

    short int n, m, r, k, i, j;
    cin >> n >> m >> r >> k;
                     //u/d,  l/r
    bool arr[n][m], arr2[n][m];
    for(i = 0; i < n; i++) memset(arr[i], 0, m*sizeof(bool));
    arr[(r-1)/m][(r-1)%m] = true;
    for( ; k; k--){
        for(i = 0; i < n; i++) memset(arr2[i], 0, m*sizeof(bool));
        for(i = 0; i < n; i++)
            for(j = 0; j < m; j++)
                if(arr[i][j]){
                    if(j+1 < m) arr2[i][j+1] = true;
                    if(i   > 0) arr2[i-1][j] = true;
                    if(i+1 < n) arr2[i+1][j] = true;
                    if(j   > 0) arr2[i][j-1] = true;
                }
        for(i = 0; i < n; i++) memcpy(arr[i], arr2[i], m*sizeof(bool));
    }

    int sum = 0;
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++)
            if(arr[i][j]) sum += i*m + j + 1;
    }

    cout << sum << endl;
    return 0;
}
