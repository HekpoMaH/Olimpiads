#include<bits/stdc++.h>
using namespace std;
int f[209][209];//,fr[209][209];
int k,n,s[209],ps[209];
int main()
{
    cin>>k;
    int x;
    while(cin>>x)
    {
        n++;
        s[n]=x;
        ps[n]=ps[n-1]+x;
    }
    //for(int i=1;i<=n;i++)cout<<ps[i]<<" ";cout<<endl;
    memset(f,31,sizeof(f));
    for(int i=1;i<=k;i++)
    {
        f[1][i]=s[1];
    }
    for(int i=1;i<=n;i++)
    {
        f[i][1]=ps[i];
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<=k;j++)
        {
            for(int p=1;p<i;p++)
            {
                f[i][j]=min(f[i][j],max(f[p][j-1],ps[i]-ps[p]));
            }
        }
    }
    cout<<"minimalnoto vreme e: "<<f[n][k]<<endl;
    int minimalnovr=f[n][k],sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=s[i];
        if(sum>minimalnovr)cout<<endl,sum=s[i];
        cout<<s[i]<<" ";
    }
    cout<<endl;
}
/*
4
23 15 89 170 25 1 86 80 2 27
*/
