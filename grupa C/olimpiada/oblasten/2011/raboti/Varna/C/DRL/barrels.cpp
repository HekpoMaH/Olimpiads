#include <iostream>
using namespace std;
int main ( ) {
    long long int S, N, n, max=0, i;
    cin >> S >> N;
    for (i=1;i<=N;i++)
        {
        cin >> n;
        if (max<=n) max=n;
        }
    if (S%max!=0) cout << S/max+1;
    else cout << S/max;
    cout << endl;
    return 0;
}
