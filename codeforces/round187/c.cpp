#include<iostream>
using namespace std;
long long ans,t,a[200009];
long long n,k,br;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=2;i<n;i++)
    {
        ans=t-((i-1-br)*(n-i)*a[i]);
        if(ans<k){cout<<i<<endl;br++;}
        else t+=a[i]*(i-br-1);
    }
}
