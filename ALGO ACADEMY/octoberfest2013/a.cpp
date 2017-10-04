#include<bits/stdc++.h>
using namespace std;
int aa[10000];
int n;
int a,b;
int main()
{
    cin>>n;
    cin>>a>>b;
    for(int i=0;i<n;i++)cin>>aa[i];
    sort(aa+a,aa+b+1);
    for(int i=0;i<n-1;i++)cout<<aa[i]<<" ";cout<<aa[n-1]<<endl;
}
