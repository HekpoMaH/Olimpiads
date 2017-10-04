#include<iostream>
#include<algorithm>
using namespace std;
int a[20000];
int n,s;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--)
    {
        if(i<=n-3&&a[i]<=0)break;
        s+=a[i];
    }
    cout<<s<<endl;
}