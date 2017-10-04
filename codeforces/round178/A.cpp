#include<iostream>
#include<string>
#include<iomanip>
#include<algorithm>
#include<cmath>
using namespace std;
int a[101];
int n,m,x,y;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        a[x]--;
        a[x]-=y-1;
        a[x-1]+=y-1;
        a[x+1]+=a[x];
        a[x]=0;
    }
    for(int i=1;i<=n;i++)cout<<a[i]<<endl;
}
