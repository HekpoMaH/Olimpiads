#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
int n,a,b,m;
int g[50][50],br,used[50],gr,nxt;vector<int> ans[90];
set<int> kids;
void dfs(int node)
{
    kids.erase(node);
    ans[nxt].push_back(node);
    used[node]=1;
    for(int i=1;i<=n;i++)if(g[node][i]==1&&used[i]==0)
    {
        dfs(i);
    }
}

int main()
{
    cin>>n>>m;gr=n/3;
    for(int i=1;i<=n;i++)kids.insert(i);
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b;
        g[a][b]=g[b][a]=1;
    }
    for(int i=1;i<=n;i++)
    {
        if(used[i]==0)
        {
            for(int j=1;j<=n;j++)
            {
                if(g[i][j]!=0)
                {
                    nxt++;
                    //br=0;
                    dfs(i);
                    break;
                }
            }

        }
    }
    //cout<<"ada"<<nxt<<endl;
    for(int i=1;i<=nxt;i++)
    {

        if(ans[i].size()>3)
        {
            cout<<-1<<endl;
            return 0;
        }
        if(ans[i].size()<3)
        {   //cout<<"INC@"<<endl;
            while(ans[i].size()<3&&kids.size()!=0)
            {
                ans[i].push_back(*kids.begin());
                kids.erase(kids.begin());
            }
            if(kids.size()==0&&ans[i].size()<3)
            {
                cout<<-1<<endl;
                return 0;
            }
        }
    }
    while(nxt<gr)
    {
        nxt++;
        //cout<<"INC!"<<endl;
        while(ans[nxt].size()<3&&kids.size()!=0)
        {
            ans[nxt].push_back(*kids.begin());
            kids.erase(kids.begin());
        }
        if(kids.size()==0&&ans[nxt].size()<3)
            {
                cout<<-1<<endl;
                return 0;
            }
    }
    //cout<<"NX"<<nxt<<endl;
    for(int i=1;i<=nxt;i++)
    {
        cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<endl;
    }
}


