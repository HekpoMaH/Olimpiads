#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<iomanip>
using namespace std;
int n,m;
int a,br0,br1;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){cin>>a;if(a==1)br1++;if(a==-1)br0++;}
    for(int i=1;i<=m;i++)
    {
        int l,r;cin>>l>>r;
        if(br0>=(r-l+1)/2&&br1>=(r-l+1)/2&&(r-l+1)%2==0)cout<<1<<endl;
        else cout<<0<<endl;
    }
}
