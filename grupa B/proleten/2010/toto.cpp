#include<iostream>
using namespace std;
int a[9],b[9];
int ansa,ansb;
int comb(int n,int k)
{
    if(k<0||k>n)return 0;
    if(k>n-k)k=n-k;
    if(k==0)return 1;
    long long c=n;
    for(int i=2;i<=k;i++)
    c=c*(n-i+1)/i;
    return c;
}
int calc(int x[])
{
    int re=0;//haha
    for(int i=1;i<=6;i++)
    {
        for(int k=x[i-1]+1;k<x[i];k++)
        {
            re+=comb(49-k,6-i);
        }
    }
    return re;
}
int main()
{
    for(int i=1;i<=6;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=6;i++)cin>>b[i];
    ansa=calc(a);
    ansb=calc(b);
    //cout<<ansa<<" "<<ansb<<endl;
    cout<<max(0,ansb-ansa-1)<<endl;
}
