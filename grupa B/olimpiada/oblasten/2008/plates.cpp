#include<bits/stdc++.h>
using namespace std;
const int Mmax=1000;
const int Nmax=30;
int t[Mmax+1][Nmax+1][Nmax+1];
int u[Mmax+1];
int m,n;
void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int c=1;c<=m;c++)
    {
        for(int i=1;i<=n;i++)
        {
            string s;
            cin>>s;
            for(int j=1;j<=n;j++)
            {
                if(s[j-1]=='1')t[c][i][j]=1;
            }
        }
    }
}
void sh(int i0,int j0,int &i,int &j)
{
    i=1+n-i0;
    j=j0;
}
void sv(int i0,int j0,int &i,int &j)
{
    i=i0;
    j=1+n-j0;
}
void sd(int i0,int j0,int &i,int &j)
{
    i=j0;j=i0;
}
void ss(int i0,int j0,int &i,int &j)
{
    sd(i0,j0,i,j);
    i0=i;j0=j;
    sh(i0,j0,i,j);
    i0=i;j0=j;
    sv(i0,j0,i,j);
}
void trans(int n,int i0,int j0,int &i,int &j)
{
    switch(n)
    {
        case 1:sh(i0,j0,i,j);return;
        case 2:sv(i0,j0,i,j);return;
        case 3:sd(i0,j0,i,j);return;
        case 4:ss(i0,j0,i,j);return;
    }
    sv(i0,j0,i,j);
    i0=i,j0=j;
    switch(n)
    {
        case 5:sh(i0,j0,i,j);return;
        case 6:sv(i0,j0,i,j);return;
        case 7:sd(i0,j0,i,j);return;
        case 8:ss(i0,j0,i,j);return;
    }
}
bool same(int r,int k1,int k2)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int it,jt;
            trans(r,i,j,it,jt);
            if(t[k1][i][j]!=t[k2][it][jt])return false;
        }
    }
    return true;
}
void reduce()
{
    for(int r=1;r<=8;r++)
    {
        for(int k2=2;k2<=m;k2++)
        if(u[k2]==0)for(int k1=1;k1<k2;k1++)
        {
            if(u[k1]==0)if(same(r,k1,k2)){u[k2]=1;break;}
        }
    }
}
int main()
{
    input();
    reduce();
    int br=0;
    for(int k=1;k<=m;k++)
    {
        if(u[k]==0)br++;
    }
    cout<<br<<"\n";
}
