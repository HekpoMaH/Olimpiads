#include<iostream>
using namespace std;
int main () {
    long long int i,j,s,n,br=0;
    cin >> s >> n ;
    long long int a[n];
    for (i=0; i<n; i++) {
        cin >> a[i] ;
        }
    sort(a,a+n);
    for (i=n-1; i>=0; i--) {
        br+=s/a[i];
        s%=a[i];
        }
    cout << br ;
    cout << endl ;
    system ("PAUSE");
    return 0;
} 
