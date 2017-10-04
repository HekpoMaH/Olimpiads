#include<iostream>
#include<cmath>
using namespace std;
int main() {
    long n,a,b,min=1000001,a1,b1;
    cin >> n;
    for(a=1;a<=n/2;a++)
    for(b=1;b<=n/2;b++)
    if(a*b==n && a<=b && fabs(a-b)<min) {a1=a; b1=b;}
    cout << a1 << ' ' << b1 << endl;
    return 0;
}
