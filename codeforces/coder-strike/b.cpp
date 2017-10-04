#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int maxn=109;
int x[maxn][maxn];
bool lockedcells[maxn];
int lockedcores[maxn];
vector<int> writing[maxn];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>x[j][i];
        }
    }
    for(int i=1;i<=m;i++)
    {
        memset(writing,0,sizeof(writing));
        for(int j=1;j<=n;j++)
        {
            if(x[i][j]==0)continue;
            if(lockedcores[j]==0)
            {
                if(lockedcells[x[i][j]]==true)
                {
                    lockedcores[j]=i;
                }
                else writing[x[i][j]].push_back(j);
            }
        }
        for(int j=1;j<=k;j++)
        {
            if(writing[j].size()>=2)
            {
                for(int ss=0;ss<writing[j].size();ss++)
                {
                    lockedcores[writing[j][ss]]=i;
                }
                lockedcells[j]=true;
            }
        }
    }
    for(int i=1;i<=n;i++)cout<<lockedcores[i]<<"\n";
}
