#include<iostream>
#include<algorithm>
using namespace std;
int a[104];
int n,s,s2,br;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],s+=a[i];
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--)
    {
        s2+=a[i];
        br++;
        if(s2>s-s2)break;
    }
    cout<<br<<endl;
    return 0;
}