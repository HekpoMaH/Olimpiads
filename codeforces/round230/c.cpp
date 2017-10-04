#include<bits/stdc++.h>
using namespace std;
int n;
long long ans=1;
int a[40000009];
set<long long> seq;
int main()
{
    cin>>n;
    a[1]=1;
    seq.insert(a[1]);long long x;double x1;
    for(int i=2;i<=n+4;i++)
    {
        x1=floor((double)(sqrt(a[i-1])));x=(int)x1;
        if(seq.find(x)==seq.end())a[i]=x;
        else a[i]=2*a[i-1];
        //cout<<x<<" "<<2*a[i-1]<<endl;
        seq.insert(a[i]);
    }
    cout<<a[n+2]<<endl;
}
