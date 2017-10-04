#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int> > g;
vector<vector<bool> >pos;
int optimal[20001];
int n;
int a,b;
int f(int start)
{
    queue<int> q;
    int used[20001],res=0,cur;
    memset(used,0,sizeof(used));
    q.push(start);
    used[start]=1;
    while(!q.empty())
    {
        cur=q.front();q.pop();
        for(int i=0;i<g[cur].size();i++)
        {
            if(!used[g[cur][i]])
            {
                if(pos[cur][i]==false)res++;
                used[g[cur][i]]=1;
                q.push(g[cur][i]);
            }
        }
    }
    return res;
}
void gg()
{
    queue<int> q;
    int used[20001],cur;
    memset(used,0,sizeof(used));
    q.push(0);
    used[0]=1;
    while(!q.empty())
    {
        cur=q.front();q.pop();
        for(int i=0;i<g[cur].size();i++)
        {
            if(!used[g[cur][i]])
            {
                used[g[cur][i]]=1;
                q.push(g[cur][i]);
                optimal[g[cur][i]]=optimal[cur];
                if(pos[cur][i]==true)optimal[g[cur][i]]++;
                else optimal[g[cur][i]]--;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    g.resize(n);
	pos.resize(n);
    for(int i=1;i<n;i++)
    {
        cin>>a>>b;
        a--;b--;//cout<<"WTF"<<endl;
        g[a].push_back(b);
        g[b].push_back(a);
        pos[a].push_back(true);
        pos[b].push_back(false);
    }
    
    optimal[0]=f(0);
    
    gg();
    int mn=optimal[0];
    for(int i=1;i<n;i++)
    {
        mn=min(optimal[i],mn);
    }//cout<<optimal[1]<<endl;
    cout<<mn<<endl;
    for(int i=0;i<n;i++)
    {
        if(optimal[i]==mn)
        {
            cout<<i+1<<" ";
        }
    }
    cout<<endl;
    return 0;
}