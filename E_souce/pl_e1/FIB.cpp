#include<iostream>
using namespace std;
int main() {
    int n,i;
    long a=1,b=0,t;
    cin >> n;
    for(i=1;i<n;i++) {
                      t=a;
                      a+=b;
                      b=t;
    }
    cout << a << endl;
    system("PAUSE");
    return 0;
}
