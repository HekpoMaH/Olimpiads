#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[2009];
int b[2009];
void read()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int mx,mxi;
    for(int i=1;i<=k;i++)
    {
        mx=0;mxi=1;
        for(int j=1;j<n;j++)
        {
            if(abs(a[j+1]-a[j])>mx)mx=abs(a[j+1]-a[j]),mxi=j;
        }
        if(a[mxi]>0){a[mxi]=min(a[mxi],a[mxi+1]);
        a[mxi+1]=a[mxi];}
        else {a[mxi]=max(a[mxi],a[mxi+1]);
        a[mxi+1]=a[mxi];}
    }
    for(int i=1;i<=n;i++)cout<<a[i]<<" ";
    cout<<endl;
    mx=0;mxi=1;
    for(int j=1;j<n;j++)
    {
        if(abs(a[j+1]-a[j])>mx)mx=abs(a[j+1]-a[j]),mxi=j;
    }
    cout<<mx<<endl;
}
int main()
{
    read();
}
