#include<iostream>
#include<cstring>
using namespace std;
int used2[12];
int used[12],ans;
int main()
{
    int n,m,t,b,x,l,y,x1,y1,c;
    cin>>n>>m;
    t=m;
    cin>>x1>>y1;
    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        memset(used,0,sizeof(used));
        memset(used2,0,sizeof(used2));
        used[x]=used[y]=used[7-x]=used[7-y]=1;
        b=7-t;
        l=0;
        //cout<<b<<endl;
        for(int j=1;j<=6;j++)
        {if(used[j]==0&&j==b)l=1;if(used[j]==0&&j!=b)c=i;}
        if(l==0){ans=1;}
        x1=x,y1=y;t=c;
        //cout<<t<<endl;
    }
    if(!ans)cout<<"YES"<<endl;
    if(ans)cout<<"NO"<<endl;
    return 0;
}