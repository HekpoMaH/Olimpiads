#include<bits/stdc++.h>
using namespace std;
const int maxn=100009;
int a[maxn],n,m;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int br=0,sum=0;a[n+1]=9999;
    for(int i=1;i<=n;i++)
    {
        sum+=a[i];
        if(sum+a[i+1]>m)br++,sum=0;
        //else sum=a[i],br++;
        //cout<<i<<" "<<br<<endl;
    }

    cout<<br<<endl;
}
