#include<iostream>
using namespace std;
int n;
int a,sum,mx;
void solve()
{
    cin>>n;sum=0,mx=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        sum+=a;
        mx=max(mx,a);
    }
    cout<<sum-mx<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}
