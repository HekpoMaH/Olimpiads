#include<iostream>
#include<cstring>
using namespace std;
int n,a[20][4],used[20],ans,cals;
void solve(int x,int y,int z)
{
    cals++;
    //cout<<x<<" "<<y<<" "<<z<<endl;
    if(z>ans)ans=z;
    for(int i=1;i<=n;i++)
    {
        if(used[i]==0)
        {
            if(a[i][1]<=x&&a[i][2]<=y){used[i]=1;solve(a[i][1],a[i][2],a[i][3]+z);used[i]=0;}
            if(a[i][1]<=x&&a[i][3]<=y){used[i]=1;solve(a[i][1],a[i][3],a[i][2]+z);used[i]=0;}
            if(a[i][2]<=x&&a[i][1]<=y){used[i]=1;solve(a[i][2],a[i][1],a[i][3]+z);used[i]=0;}
            if(a[i][2]<=x&&a[i][3]<=y){used[i]=1;solve(a[i][2],a[i][3],a[i][1]+z);used[i]=0;}
            if(a[i][3]<=x&&a[i][1]<=y){used[i]=1;solve(a[i][3],a[i][1],a[i][2]+z);used[i]=0;}  
            if(a[i][3]<=x&&a[i][2]<=y){used[i]=1;solve(a[i][3],a[i][2],a[i][1]+z);used[i]=0;}        
        }
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i][1]>>a[i][2]>>a[i][3];
    }
    for(int i=1;i<=n;i++)
    {
        memset(used,0,sizeof(used));
        used[i]=1;
        solve(a[i][1],a[i][2],a[i][3]);
        memset(used,0,sizeof(used));
        used[i]=1;
        solve(a[i][1],a[i][3],a[i][2]);
        memset(used,0,sizeof(used));
        used[i]=1;
        solve(a[i][2],a[i][1],a[i][3]);
        memset(used,0,sizeof(used));
        used[i]=1;
        solve(a[i][2],a[i][3],a[i][1]);
        memset(used,0,sizeof(used));
        used[i]=1;
        solve(a[i][3],a[i][1],a[i][2]);
        memset(used,0,sizeof(used));
        used[i]=1;
        solve(a[i][3],a[i][2],a[i][1]);
    }
    cout<<ans<<" "<<cals<<endl;
    return 0;
}
/*
5
10 10 10
50 50 50
40 40 40
20 20 20
30 30 30
*/