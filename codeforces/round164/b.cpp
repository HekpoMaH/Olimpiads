#include<iostream>
using namespace std;
long long f[5000];
int main()
{
    long long n;
    cin>>n;
    int ans=1;
    for(int i=0;i<n;i++)
    {
        ans*=2;
    }
    //cout<<ans+5;
    cout<<n*(n*n+5)/6<<endl;
}