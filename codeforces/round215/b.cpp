#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100009];
int ans[100009],used[100009];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=n;i>=1;i--)
    {
        ans[i]=ans[i+1];
        if(used[a[i]]==0)
        {
            used[a[i]]=1;
            ans[i]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        int x;
        cin>>x;
        cout<<ans[x]<<endl;
    }
}
