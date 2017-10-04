#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,q;
int tab[1002][1002],s[1002][1002];
int w[1002],k[1002],ss;
int sum(int f,int e)
{
    if(s[f][e]!=0)return s[f][e];
    for(int i=f;i<=e;i++)s[f][e]+=k[i];
    return s[f][e];
}
int main()
{
    scanf("%d %d",&n,&q);
    memset(tab,31,sizeof(tab));
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&w[i]);
        tab[i][i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&k[i]);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i<j)for(int p=i;p<=j;p++)
            {
                if(sum(p,j)<k[p]&&sum(i,p)<k[i])tab[i][j]=min(tab[i][j],tab[i][p]+tab[p][j]);
            }
            if(i>j)
            {
                ss=tab[i][n];
                ss+=tab[1][j];
                tab[j][i]=min(tab[j][i],ss);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<tab[i][j]<<" ";
        }
        cout<<endl;
    }
}