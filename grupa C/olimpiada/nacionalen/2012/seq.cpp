#include<iostream>
#define mkk (long long)(1e15)
using namespace std;
long long k,l[50],dig[10];
int n;
int cnt(int num)
{
    int br=0;
    while(num!=0){num/=10;br++;}
    return br;
}
long long len(int num)
{
    if(num>49)return mkk+1;
    return l[num];
}
int main()
{
    cin>>n>>k;
    l[1]=1;
    for(int i=2;i<50;i++)l[i]=2*l[i-1]+cnt(i);
    int t,br;
    for(int i=n;i>=1;i--)
    {
        br=cnt(i);
        if(br>=k)
        {
            t=i;
            for(int j=br-1;j>=0;j--)dig[j]=t%10, t/=10;
            cout<<dig[k-1]<<endl;
            k=0;
            return 0;
        }
        k-=br;
        if(k>len(i-1))k-=len(i-1);
    }
    if(k>0)cout<<-1<<endl;
    return 0;
}