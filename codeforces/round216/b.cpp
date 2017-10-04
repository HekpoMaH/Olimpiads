#include<bits/stdc++.h>
using namespace std;
int n,k,l,r,sall,sk;
int a[1009],b[1009];
int main()
{
    cin>>n>>k>>l>>r>>sall>>sk;
    for(int i=1;i<=k;i++)
    {
        a[i]=sk/k;
        if(i<=sk%k)a[i]++;
        cout<<a[i]<<" ";
    }
    //cout<<n-k<<" "<<sall-sk<<endl;
    for(int i=1;i<=n-k;i++)
    {
        b[i]=(sall-sk)/(n-k);
        if(i<=(sall-sk)%(n-k))b[i]++;
        cout<<b[i]<<" ";
    }cout<<endl;
}
