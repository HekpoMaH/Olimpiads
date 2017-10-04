#include<iostream>
using namespace std;
int main() {
    long n,i,k,a,b,sum=0,min=1000001,t;
    cin >> n;
    for(i=1;i<=n;i++) {
                        cin >> k;
                        if(k<min) min=k;
                        sum+=k;
    }
    cout << sum-min+1 << endl;
    return 0;
}
