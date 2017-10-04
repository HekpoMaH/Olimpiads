#include<iostream>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    unsigned long long a[128];
    a[1]=1;
    a[2]=1;
    for(int i=3;i<=n;i++){
            a[i]=0;
            for(int j=i-1;i-j<=k && j>0;j--) a[i]+=a[j];
            }
    cout << a[n] << endl;
    return 0;
}
