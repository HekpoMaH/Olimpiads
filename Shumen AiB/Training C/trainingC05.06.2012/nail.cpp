#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[100005];
long long d[100005];
int n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    //cout<<"WTF"<<endl;
    sort(a+1,a+n+1);
    d[0]=0;d[1]=0;d[2]=a[2]-a[1];d[3]=a[3]-a[1];
    for(int i=4;i<=n;i++)
    {
        d[i]=min(d[i-1]+a[i]-a[i-1],d[i-2]+a[i]-a[i-1]);
        //cout<<i<<endl;
    }
    //for(int i=1;i<=n;i++)cout<<d[i]<<" ";
    //cout<<endl;
    cout<<d[n]<<endl;
    return 0;
}