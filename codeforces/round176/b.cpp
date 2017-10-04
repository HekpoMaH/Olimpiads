#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;
typedef long long ll;
ll n,k;
ll a[1000000],used[1000000];;
ll l=99999999999;

void go(ll x,ll br)
{   if(x==n)l=min(l,br);
    for(int i=2;i<=k;i++)
    {
        if(used[i]==0)used[i]=1,go(x+i-1,br+1),used[i]=0;
    }
}
int main()
{
    cin>>n>>k;
    for(int i=2;i<=k;i++)
    {
        used[i]=1;
        go(i,1);
        used[i]=0;
    }
    if(l==99999999999)cout<<-1<<endl;
    else cout<<l<<endl;
}

