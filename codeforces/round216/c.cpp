#include<bits/stdc++.h>
using namespace std;
int u[100009],t,used[100009];
int n;
vector<int> ans;
vector<int> g[100009];map<pair<int,int>, int>mp;
bool dfs(int pred,int nod)
{
    int l;
    //cout<<nod<<"->"<<" "<<g[nod].size()<<endl;
    //for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
    //cout<<endl;
    used[nod]=1;
    if(u[nod]==1&&nod!=1&&mp[make_pair(pred,nod)]==2)
    {
        //cout<<"i end here 1"<<endl;
        ans.push_back(nod);
        return true;
    }
    l=0;
    bool p;
    for(int i=0;i<g[nod].size();i++)
    {

        if(used[g[nod][i]]==0)
        {
            p=dfs(nod,g[nod][i]);
            if(p==true)l=1;
            //cout<<"for node="<<nod<<" "<<g[nod][i]<<" "<<p<<" "<<l<<endl;
        }
    }
    //cout<<"l for node="<<nod<<" "<<l<<endl;
    if(l==0&&nod!=1&&mp[make_pair(pred,nod)]==2)
    {
        ans.push_back(nod);
        //cout<<"i end here 2"<<endl;
        return true;
    }
    //cout<<"i end with"<<" "<<l<<endl;
    if(l==1)return true;
    return false;
}

int main()
{
   cin>>n;int x,y;
   for(int i=1;i<n;i++)
   {
       cin>>x>>y>>t;
       if(x>y)swap(x,y);
       mp[make_pair(x,y)]=t;
       mp[make_pair(y,x)]=t;
       g[x].push_back(y);
       g[y].push_back(x);
       u[x]++;u[y]++;
       //if(t[i]!=0)l=1;
   }
   bool wtf=dfs(-1,1);
   cout<<ans.size()<<endl;
   sort(ans.begin(),ans.end());
   if(ans.size()!=0)
   {for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
   cout<<endl;}
}
/*
9
1 2 2
1 3 2
2 4 1
2 6 2
5 2 1
7 6 1
6 8 2
3 9 1
*/
