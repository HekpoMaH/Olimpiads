#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,a[104];
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    int s=0;
    for(int i=0;i<n-1;i++)s+=a[i];
    cout<<s<<endl;
    return 0;
}
