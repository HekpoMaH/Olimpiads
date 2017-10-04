#include<bits/stdc++.h>
using namespace std;
unsigned long long d[(1<<8)+9][(1<<8)+9];
unsigned long long n,m,mod;
unsigned long long a[(1<<8)+9];
int bit(int pr,int pos)
{
    if(pr&(1<<pos))return 1;
    return 0;
}
void calcd()
{
    for(int i=0;i<(1<<m);i++)
    {
        for(int j=0;j<(1<<m);j++)
        {
            int l=1;
            for(int t=1;t<m;t++)
            {
                if(bit(i,t)==bit(i,t-1) && bit(i,t)==bit(j,t) && bit(i,t)==bit(j,t-1)){l=0;break;}
            }
            //cout<<"l="<<l<<endl;
            if(l==1)d[i][j]=1;
            else d[i][j]=0;
        }
    }
}
void umn(unsigned long long x1[][(1<<8)+9],unsigned long long x2[][(1<<8)+9])
{
    unsigned long long x3[(1<<8)+9][(1<<8)+9];
    memset(x3,0,sizeof(x3));
    for(int i=0;i<(1<<m);i++)
    {
        for(int j=0;j<(1<<m);j++)
        {
            for(int t=0;t<(1<<m);t++)
            {
                x3[i][j]=(x3[i][j]+(x1[i][t]*x2[t][j]));
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
void povd(unsigned long long x[][(1<<8)+9],unsigned long long p)
{
    unsigned long long ans[(1<<8)+9][(1<<8)+9];
    for(int i=0;i<(1<<m);i++)for(int j=0;j<(1<<m);j++)
    {
        if(i==j)ans[i][j]=1;
        else ans[i][j]=0;
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
    if(n<m)swap(n,m);
    calcd();
    povd(d,n-1);
    //a[0][0]=1;
    //for(int i=0;i<(1<<m);i++)
    //{
    //    for(int j=0;j<(1<<m);j++)cout<<d[i][j]<<" ";
    //    cout<<endl;
    //}
    for(int i=0;i<(1<<m);i++)a[i]=1;
    //a[0][0]=0;
    //unsigned long long sum=0;
    //for(int i=0;i<(1<<m);i++){
    //   for(int j=0;j<(1<<m);j++){
    //      sum+=d[i][j];
    //   }
    //}
    unsigned long long sum=0;
    for(int i=0;i<(1<<m);i++){
       for(int j=0;j<(1<<m);j++){
          sum+=d[i][j];
       }
    }
    cout<<sum<<"\n";
}
