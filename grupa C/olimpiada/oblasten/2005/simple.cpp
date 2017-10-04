#include<iostream>
using namespace std;
int m[102],x[102],y[102];
int n,p,mn,mx,br;
int main()
{
    cin>>n>>p;
    for(int i=1;i<=n;i++)
    {
        mn=1001;mx=0;
        for(int j=1;j<=p;j++)
        {
            cin>>m[j];
            if(m[j]<mn)mn=m[j];
            if(m[j]>mx)mx=m[j];
        }
        for(int j=1;j<=p;j++)
        {
            if(m[j]==mn)x[j]++;
            if(m[j]==mx)y[j]++;
        }
    }
    for(int i=1;i<=p;i++)if(x[i]>=n/2&&y[i]==0)cout<<i<<" ";
    cout<<endl;
    return 0;
}
