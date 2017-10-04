#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int n;
int r[15];
int used[10006];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>r[i];
    }
    int res;
    for(int i=0;i<(1<<n);i++)
    {
        for(int j=0;j<=10002;j++)
        {
            res=j;
            for(int k=1;k<=n;k++)
            {
                //cout<<i<<"   "<<k<<" "<<(i&(1<<(k-1)))<<endl;
                if((i&(1<<(k-1)))!=0)res+=r[k];
                else res-=r[k];
            }
            //cout<<i<<" "<<j<<" "<<res<<endl;
            if(res>=-1&&res<=1)used[j]=1;
        }

    }
    int ls[10005],rs[10005];
    int br1=0,br2=0,st=1;
    for(int i=0;i<=10002;i++)
    {
        if((i==0&&used[i]==1)||(used[i]==1&&used[i-1]==0))br1++,ls[br1]=i;
        if(used[i]==1&&used[i+1]==0)br2++,rs[br2]=i;
    }
    if(ls[1]==0)cout<<br1*2-1<<endl;
    else cout<<br1*2<<endl;
    for(int i=br1;i>=1;i--)
    {
        if(ls[i]==0)
        {
            cout<<-rs[i]<<" "<<rs[1]<<endl;st=2;
        }
        else cout<<-rs[i]<<" "<<-ls[i]<<endl;
    }//cout<<st<<" "<<br1<<endl;
    for(int i=st;i<=br1;i++)cout<<ls[i]<<" "<<rs[i]<<endl;
    return 0;
}

