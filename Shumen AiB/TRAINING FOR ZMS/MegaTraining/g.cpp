#include<iostream>
using namespace std;
void solve()
{
    int a,b,n,br=0;
    cin>>n>>a>>b;
    for(int i=0;i<=n;i++)
    {
        if(i<=a&&n-i<=b)br++;
    }
    cout<<br<<endl;
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
