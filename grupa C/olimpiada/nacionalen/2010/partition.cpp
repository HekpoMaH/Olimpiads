#include<iostream>
using namespace std;
long long n,a[100000];
int main()
{
    cin>>n;
    a[2]=1;a[3]=1;a[4]=1;
    for(int i=5;i<n;i++)a[i]=(a[i-1]+a[i-3])%1000000007;
    cout<<a[n-1]<<endl;
    return 0;
}
