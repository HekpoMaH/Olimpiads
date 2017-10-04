#include<bits/stdc++.h>
using namespace std;
const int nmax=100009;
int n,a[nmax],m,a2[nmax];
long long ans,x,y;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)cin>>a[i];
    ans=1;
    for(int i=1;i<63;i++)ans*=2;
    //cout<<ans<<"\n";
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            long long curr=0;
            //merge i to j
            //i=1; j=5;
            for(int k=1;k<=m;k++)
            {
                a2[k]=a[k];
                if(a2[k]==i)a2[k]=j;
                //cout<<a2[k]<<" ";
            }//cout<<"\n";
            for(int k=1;k<m;k++)
            {
                curr+=(long long)abs(a2[k]-a2[k+1]);
            }
            //cout<<"cur="<<curr<<endl;
            ans=min(ans,curr);
            if(ans==curr)
            {
                x=i;y=j;
            }//cout<<ans<<" "<<x<<" "<<y<<"\n";
        }
    }
    cout<<ans<<"\n";cerr<<" "<<x<<" "<<y<<"\n";
}
