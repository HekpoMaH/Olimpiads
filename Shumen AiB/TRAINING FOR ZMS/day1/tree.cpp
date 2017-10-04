#include<iostream>
#include<vector>
#include<cmath>
#include<set>
using namespace std;
vector<long long> g[100009],df;
long long n,v[100009];
long long used[100009],x,sum,plu[100009],minu[100009],br;
void dfs(int node)
{
    //cout<<node<<endl;
    used[node]=1;
    //for(int i=1;i<=n;i++)cout<<used[node]<<" ";
    //cout<<endl;
    long long mxpl=0,mxmi=0;
    for(int i=0;i<g[node].size();i++)
    {
        if(used[g[node][i]]==0)
        {
            //cout<<"AAAEEAEA"<<endl;
            dfs(g[node][i]);
            mxpl=max(mxpl,plu[g[node][i]]);
            mxmi=max(mxmi,minu[g[node][i]]);
        }
    }
    if(v[node]+mxpl>mxmi)
    {
        plu[node]=mxpl;
        minu[node]=mxpl+v[node];
    }
    else
    {
        minu[node]=mxmi;
        plu[node]=minu[node]-v[node];
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);g[b].push_back(a);
    }
    for(int i=1;i<=n;i++){cin>>v[i];}
    dfs(1);
    for(int i=1;i<=n;i++)
    {
        //cout<<plu[i]<<" "<<minu[i]<<endl;
    }
    sum=minu[1]+plu[1];
    cout<<sum<<endl;
}
