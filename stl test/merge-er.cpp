#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a,int b)
{
    if(a>b)return true;
    return false;
}
int main()
{
    int a[10],b[10];
    int n,m;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    cin>>m;
    for(int i=1;i<=m;i++)cin>>b[i];
    int c[20];
    merge(a+1,a+n+1,b+1,b+m+1,c,cmp);
    for(int i=0;i<n+m;i++)cout<<c[i]<<" ";
    return 0;
}