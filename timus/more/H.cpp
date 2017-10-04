#include<iostream>
using namespace std;
int n;
long long p,a[1000005],x,d,ct;
struct kup
{
    int val,num;
};
kup k[1006];
int br;
int main()
{
    cin>>n>>p;
    for(int i=1;i<=n;i++)cin>>x,a[x]++;
    for(int i=1;i<=1000000;i++)
    {
        if(a[i]>0)
        {
            br++;
            k[br].val=i;
            k[br].num=a[i];
        }
        //cout<<i<<endl;
    }
    int sum=0,d1=0;
    for(int i=1;i<=br;i++)
    {

    }
    cout<<d<<" "<<ct<<endl;
    return 0;
}
