#include<bits/stdc++.h>
using namespace std;
int n,m;
struct el
{
    long long st,a,b,mod;
    el(){}
    el(long long _st,long long _a,long long _b,long long _mod)
    {
        st=_st;
        a=_a;
        b=_b;
        mod=_mod;
    }
    bool operator < (const el &f)const
    {
        return f.st<st;
    }
};
priority_queue<el> pq;
vector<long long> ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ifstream fin("arrays.in");
    ofstream fout("arrays.out");
    int n,m;
    fin>>n;
    long long a,b,c,d;
    for(int i=1;i<=n;i++)
    {
        fin>>a>>b>>c>>d;
        pq.push(el(a,b,c,d));
    }
    for(int i=1;i<=300009;i++)
    {
        el cur=pq.top();
        pq.pop();
        ans.push_back(cur.st);
        cur.st=cur.st+(cur.st*cur.a+cur.b)%cur.mod;
        pq.push(cur);
    }
    fin>>m;
    //for(int i=0;i<15;i++)cout<<ans[i]<<" ";cout<<endl;
    for(int i=1;i<=m;i++)
    {
        int q;
        fin>>q;
        fout<<ans[q-1]<<"\n";
    }

}
