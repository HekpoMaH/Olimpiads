#include<iostream>
#include <algorithm>
using namespace std;
int main ()
{
    int S, n, barrel[128];
    cin >> S >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> barrel [i];
    }
    sort (barrel+0, barrel + n);
    if( S % barrel[n-1] == 0 ) cout << S / barrel [n-1] << endl;
    else if (S % barrel[n-1] == 1) cout << S / barrel[n-1] + 1 << endl;
    else if (S%barrel[n-1] == 2 && barrel[1] == 2) cout << S / barrel[n-1] + 1 << endl;
    else if (S % barrel [n-1] == 3 && barrel[1] == 3) cout << S / barrel[n-1] + 3 << endl;
    else cout << S / barrel [n-1] + 2 << endl;
    return 0;
}