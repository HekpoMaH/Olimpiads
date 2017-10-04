#include<iostream>
using namespace std;
int n,k;
int mem[100];
int go(int x)
{
    if(mem[x]!=0)
    {
        return mem[x];
    }
    for(int i=1;i<=k&&i<=x;i++)if(go(x-i)==-1){return mem[x]=1;}
    cout<<x<<"->"<<endl;
    for(int i=x;i>=x-k;i--)
    {
        cout<<mem[i]<<" ";
    }cout<<endl;
    return mem[x]=-1;
}
int main()
{
    cin>>n>>k;mem[0]=-1;
    int ff=go(n);
    if(ff==-1)cout<<0<<endl;
    else
    {
        cout<<1<<" ";
        //cout<<endl;
        //for(int i=)
        for(int i=n;i>=0;i--)
        if(mem[i]==-1){cout<<n-i<<endl;return 0;}
    }
}
