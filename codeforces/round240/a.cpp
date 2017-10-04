#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[109];
int b[109];
int ans[109];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>b[i];
        for(int j=b[i];j<=n;j++)
        {
            if(a[j]==0)
            {

                a[j]=1;
                ans[j]=b[i];
            }
        }
    }
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";cout<<endl;
}
