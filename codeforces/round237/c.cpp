#include<bits/stdc++.h>
using namespace std;
int n,k;
int d[100009],used[100009],brv,st[100009];
map<int,vector<int> > mp;
vector<pair<int,int> >v;
void read()
{
    cin>>n>>k;
    int br=0;
    for(int i=1;i<=n;i++)
    {
        cin>>d[i];if(d[i]==0)br++;
        mp[d[i]].push_back(i);
    }
    if(br>1||br==0){cout<<-1<<"\n";exit(0);}
}
void dfs(int node,int depth)
{
    //cout<<"node="<<node<<" depth="<<depth<<endl;
    used[node]=1;
    brv++;
    for(int i=0;i<mp[depth].size();i++)
    {
        if(used[mp[depth][i]]>=1||st[node]==k);
        else
        {
            v.push_back(make_pair(node,mp[depth][i]));
            st[node]++;st[mp[depth][i]]++;
            swap(mp[depth][i],mp[depth][mp[depth].size()-1]);
            int tog=mp[depth][mp[depth].size()-1];
            mp[depth].pop_back();
            dfs(tog,depth+1);
            i--;
        }
    }
}
void solve()
{
    for(int i=1;i<=n;i++)
    {
        if(d[i]==0)
        {
            dfs(i,1);
        }
    }
    if(n==1&&d[1]==0){cout<<0<<endl;exit(0);}
    for(int i=1;i<=n;i++)
    {
        if(st[i]>k||st[i]==0){cout<<-1<<"\n";exit(0);}
    }
    cout<<v.size()<<"\n";
    for(int i=0;i<v.size();i++)
    {
        printf("%d %d\n",v[i].first,v[i].second);
    }
}
int main()
{
    read();
    solve();
}
