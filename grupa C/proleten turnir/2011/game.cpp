#include<iostream>
using namespace std;
int a[203],b[203];
int w[1000000][2];
int n,m,s,wl;
int main()
{
    cin>>s>>wl;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    cin>>m;
    for(int i=1;i<=m;i++)cin>>b[i];
    for(int ss=1;ss<=s;ss++)
    {
        for(int i=1;i<=n;i++)if(ss-a[i]>=0&&w[ss-a[i]][2]==0){w[ss][1]=1;break;}
        for(int i=1;i<=m;i++)if(ss-b[i]>=0&&w[ss-b[i]][1]==0){w[ss][2]=1;break;}
    }
    cout<<w[s][wl]<<endl;
    return 0;
}