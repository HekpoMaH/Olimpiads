#include<iostream>
using namespace std;
int main() {
    char znak;
    int v,k,n,i;
    cin >> v >> k >> n;
    for(i=1;i<=n;i++) {
                      cin >> znak;
                      if(znak=='+') v+=k;
                      if(znak=='-') v-=k;
    }
    cout << v << endl;
    return 0;
}
