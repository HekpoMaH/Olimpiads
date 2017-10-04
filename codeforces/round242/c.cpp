#include<bits/stdc++.h>
using namespace std;
int n,p[1000009],q[1000009],ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    //for(int i=1;i<=n;i++)cin>>p[i];
    for(int i=1;i<=n;i++)
    {
        int x=0;
        for(int j=1;j<=n;j++)x^=i%j,cout<<i%j<<" ";
        cout<<endl;
        q[i]=x^p[i];
        ans^=q[i];
    }
    cout<<ans<<endl;
}
