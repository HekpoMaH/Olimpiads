#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,a,b;
int getmin(int tx,int ty)
{
    if(tx%a!=i%a)return 9999999;
    if(ty%b!=j%b)return 9999999;
    if((abs(tx-i))/a+abs(ty-j)/b)%2!=0)max((abs(tx-i))/a,(abs(ty-j))/b);
}
int main()
{
    cin>>n>>m>>i>>j>>a>>b;
    if((i+a>n&&i-a<1)||(j+b>m&&j-b<1))
    {
        cout<<"Poor Inna and pony!\n";
    }
    int ans=min(min(getmin(1,1),getmin(1,m)),min(getmin(n,1),getmin(n,m)));
    if(ans>=9999999)cout<<"Poor Inna and pony!\n";
    else cout<<ans<<endl;
}
