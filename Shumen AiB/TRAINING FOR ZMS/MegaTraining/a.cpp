#include<iostream>
using namespace std;
void solve()
{
    int a,b,n,k;
    cin>>n>>k>>a>>b;
    k--;
    int tt=min(n,k),br=0;
    while(a>=tt*b)
    {//cout<<a<<endl;
        a-=tt*b;br+=tt;br++;
    }
    br+=a/b;
    cout<<br<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)solve();
}
