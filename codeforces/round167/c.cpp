#include<iostream>
using namespace std;
long long n,m;
long long l,a[1000000],w,h;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    cin>>m;l=a[0];
    for(int i=1;i<=m;i++)
    {
        cin>>w>>h;
        cout<<max(l,a[w])<<endl;
        l=max(l,a[w])+h;
    }
}
