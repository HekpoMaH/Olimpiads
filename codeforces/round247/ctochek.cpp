#include<bits/stdc++.h>
using namespace std;
int n,k,d;
int br;

void go(int sum,int l)
{
    //cout<<sum<<" "<<l<<"\n";
    if(sum==n&&l==1)
    {
        br++;
        return;
    }
    if(sum>n)return;
    for(int i=1;i<=k;i++)
    {
        if(i>=d)go(sum+i,l|1);
        else go(sum+i,l);
    }
}
int main()
{
    cin>>n>>k>>d;go(0,0);
    cout<<br<<"\n";
}
