#include<bits/stdc++.h>
using namespace std;
int a[1030][1030];
int used[1039],pred[1029];
int n;
vector<int> v[1029];
void dfs(int v,int l)
{
    used[v]=1;
    for(int i=1;i<=n;i++)
    {
        if(i!=v)
        {
            if(a[1][i]==a[v][i]+l)
            {
                if(a[i][pred[i]]>a[v][i])pred[i]=v;
                if(used[i]==0)dfs(i,l+a[i][v]);
            }
        }
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)pred[i]=1;
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            cin>>a[i][j];a[j][i]=a[i][j];
        }
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)
    {
        if(i!=pred[i])
        {
            v[i].push_back(pred[i]);
            v[pred[i]].push_back(i);
        }
    }
    for(int i=1;i<=n;i++)
    {
        sort(v[i].begin(),v[i].end());
        cout<<v[i].size();
        for(int j=0;j<v[i].size();j++)
        {
            cout<<" "<<v[i][j];
        }
        cout<<endl;
    }
}
