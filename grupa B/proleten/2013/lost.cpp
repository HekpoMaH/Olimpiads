//using map
#include<bits/stdc++.h>
using namespace std;
const int maxn=1000009;
vector<int> g[maxn];
int n;
string s1,s2,x;
int idx;
map<string,int> m;
map<int,string> m2;
void dobavi(string s)
{
    if(m[s]==0)
    {
        m[s]=++idx;
        m2[idx]=s;
    }
}
int sidx,eidx;
int ans[1000009],used[1000009],uk1,uk2;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>s1>>s2;
    dobavi(s1);dobavi(s2);
    sidx=m[s1];eidx=m[s2];
    for(int i=1;i<n;i++)
    {
        cin>>s1>>s2;
        dobavi(s1);dobavi(s2);
        g[m[s1]].push_back(m[s2]);
        g[m[s2]].push_back(m[s1]);
    }
    int l=1;uk1=1;uk2=n+1;
    used[sidx]=used[eidx]=1;
    ans[uk1]=sidx;
    ans[uk2]=eidx;
    //cout<<sidx<<" "<<eidx<<"\n";
    uk1=2;uk2=n;
    while(l)
    {
        l=0;
        int lel=ans[uk1-1];
       // cout<<lel<<"e\n";
        for(int i=0;i<g[lel].size();i++)
        {
            //cout<<g[lel][i]<<" ";
            if(used[g[lel][i]]==0)
            {
                used[g[lel][i]]=1;
                l=1;
                ans[uk1]=g[lel][i];
                uk1++;
                break;
            }
        }
    }
    l=1;
    while(l)
    {
        l=0;
        int lel=ans[uk2+1];
        for(int i=0;i<g[lel].size();i++)
        {
            //cout<<hsd[g[lel][i]]<<" ";
            if(used[g[lel][i]]==0)
            {
                used[g[lel][i]]=1;
                l=1;
                ans[uk2]=g[lel][i];
                uk2--;
                break;
            }
        }
        //cout<<"\n";
    }
    for(int i=1;i<=n+1;i++)cout<<m2[ans[i]]<<"\n";
}
