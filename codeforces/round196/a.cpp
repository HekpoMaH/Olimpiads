#include<bits/stdc++.h>
using namespace std;
int m,n,a[100],mn=99999;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    cin>>a[i];
    sort(a+1,a+m+1);
    if(m==n)cout<<a[n]-a[1]<<endl;
    else{for(int i=1;i<=m-n+1;i++)if(a[i+n-1]-a[i]<mn)mn=a[i+n-1]-a[i];
    cout<<mn<<endl;}
}
