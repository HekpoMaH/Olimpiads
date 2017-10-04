#include<bits/stdc++.h>
using namespace std;
long long p,n;
int t=4;

void solve()
{
    cin>>n;int br1=0,br2=0;
    while(n!=0)
    {
        if(n%p>2){cout<<"0"<<" ";return;}
        if(n%p==1)br1++;
        if(n%p==2)br2++;
        n/=p;
    }
    if(br1==1&&br2>0){cout<<1<<" ";return;}
    if(br1==2&&br2==0){cout<<1<<" ";return;}
    cout<<0<<" ";
}
int main()
{
    cin>>p;
    while(t--)solve();
    cout<<endl;
}
