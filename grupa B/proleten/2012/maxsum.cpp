#include<bits/stdc++.h>
using namespace std;
int mem[1001][1001][2];
int tab[1001][1001];
int dirx[5]={0,1,-1,0,0};
int diry[5]={0,0,0,1,-1};
int n,k;
void read()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&tab[i][j]);
            mem[i][j][0]=tab[i][j]+max(mem[i-1][j][0],mem[i][j-1][0]);
        }
    }
    //for(int i=1;i<=4;i++)cout<<diry[i]<<" ";cout<<endl;exit(0);
}
void go()
{
    int li,lj,x,i,j;
    int ans=0;
    if(mem[n][n][0]>ans)ans=mem[n][n][0];
    for(x=1;x<=k;x++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                int tmp=0;
                for(int k2=1;k2<=4;k2++)
                {
                    if(k2%2==1)
                    {
                        if(mem[i+dirx[k2]][j+diry[k2]][0]>0)tmp=mem[i+dirx[k2]][j+diry[k2]][0];
                    }
                    else if(k2%2==0)
                    {
                        if(mem[i+dirx[k2]][j+diry[k2]][1]>0)tmp=mem[i+dirx[k2]][j+diry[k2]][1];
                    }
                }
                mem[i][j][1]=tab[i][j]+tmp;
            }
        }
        for(i=1;i<=n;i++)for(j=1;j<=n;j++)mem[i][j][0]=mem[i][j][1];
        if(mem[n][n][0]>ans)ans=mem[n][n][0];
    }
    cout<<ans<<"\n";
}
int main()
{

    read();
    //go(1,1,0);
    go();
}

