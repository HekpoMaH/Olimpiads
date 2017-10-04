#include <iostream>
using namespace std;

int main(){
    short int m, n, k;
    cin >> m >> n >> k;
    short int arr[m][n], i, j;

    short int curr, maxr = -1, sum = 0;

    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            cin >> arr[i][j];
            sum += arr[i][j];
            if(i != 0 && j != 0){
                curr = arr[i][j]+arr[i-1][j]+arr[i][j-1]+arr[i-1][j-1];
                if(curr > maxr) maxr = curr;
            }
        }
    }
    cout << sum-maxr << endl;

    return 0;
}
