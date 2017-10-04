#include<bits/stdc++.h>
using namespace std;
int n,a[1009],v;
int main()
{
    cin>>n>>v;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int s=0;
    for(int i=1;i<n;i++)s+=a[i];
    if(s>v)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}
