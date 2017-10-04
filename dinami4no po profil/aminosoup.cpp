#include<bits/stdc++.h>
using namespace std;
long long d[(1<<7)+9][(1<<7)+9];
long long n,m;
const int ost=602214179;
void go(int p,int profile,int len)
{
    if(len==m){d[p][profile]=1;return;}
    if(!(p&(1<<len)))
    {
        go(p,profile+(1<<len),len+1);
        if(len<m-1 && !(p&(1<<(len+1))))go(p,profile,len+2);
    }
    else go(p,profile,len+1);
}
void calcd()
{
    for(int p1=0;p1<(1<<m);p1++)
    {
        go(p1,0,0);
    }
}
void umn(long long x1[][(1<<7)+9],long long x2[][(1<<7)+9])
{
    long long x3[(1<<7)+9][(1<<7)+9];
    memset(x3,0,sizeof(x3));
    for(int i=0;i<(1<<m);i++)
    {
        for(int j=0;j<(1<<m);j++)
        {
            for(int t=0;t<(1<<m);t++)
            {

                x3[i][j]=(x3[i][j]+(x1[i][t]*x2[t][j])%ost)%ost;//x3[i][j]%=ost;
                if(x3[i][j]<0){cout<<"AAA"<<endl;exit(0);}
            }
        }
    }
    for(int i=0;i<(1<<m);i++)
    {
        for(int j=0;j<(1<<m);j++)
        {
            x1[i][j]=x3[i][j];
        }
    }
}
void povd(long long x[][(1<<7)+9],long long p)
{
    long long ans[(1<<7)+9][(1<<7)+9];
    for(int i=0;i<(1<<m);i++)for(int j=0;j<(1<<m);j++)
    {
        ans[i][j]=0;
        if(i==j)ans[i][j]=1;
    }
    while(p!=0)
    {
        if(p&1)umn(ans,x);
        umn(x,x);
        p>>=1;
    }
    for(int i=0;i<(1<<m);i++)for(int j=0;j<(1<<m);j++)
    {
        x[i][j]=ans[i][j];
    }
}
int main()
{
    cin>>n>>m;
    calcd();
    //for()
    povd(d,n);
    cout<<d[0][0]%ost<<endl;
}
