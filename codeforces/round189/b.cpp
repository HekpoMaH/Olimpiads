#include<iostream>
#include<cstring>
#include<string>
#include<vector>
using namespace std;
int n;
int a[100009];
int b[100009];
int br;
int used[100009];
vector<int> v[100009];
int qt,x,y;
void dfs(int node)
{
    used[node]=1;
    for(int i=0;i<v[node].size();i++)
    {
        if(used[v[node][i]]==0)dfs(v[node][i]);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>qt>>x>>y;
        if(qt==1)
        {
            br++;
            a[br]=x;b[br]=y;
            for(int j=1;j<=br;j++)
            {
                if((a[j]<a[br]&&a[br]<b[j])||(a[j]<b[br]&&b[br]<b[j]))v[br].push_back(j),v[j].push_back(br);
            }
        }
        if(qt==2)
        {
            memset(used,0,sizeof(used));
            dfs(x);
            if(used[y]==1)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
}

