#include<iostream>
#include<cstring>
using namespace std;
int a[100][100];
int n;
int used[100];
int br;
int mn=999;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)cin>>a[i][j];
    }
    for(int bt=0;bt<(1<<n);bt++)
    {
        memset(used,0,sizeof(used));br=0;
        //cout<<1&bt<<endl;
        for(int i=1;i<=n;i++)
        {
            if((1<<(i-1))&bt)
            {br++;
                used[i]=1;
                for(int j=1;j<=n;j++)if(a[i][j]==1)used[j]=1;
            }
        }
        int l=0;
        for(int i=1;i<=n;i++)if(used[i]==0)l=1;
        if(l==0)mn=min(mn,br);
    }
    cout<<mn<<endl;
}
