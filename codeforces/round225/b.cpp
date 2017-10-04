#include<bits/stdc++.h>
using namespace std;
int n,k;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>n>>k;
    cout<<n*(n-1)/2<<"\n";
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(!k)cout<<i<<" "<<j<<"\n";
            else cout<<j<<" "<<i<<"\n";
        }
    }
}
