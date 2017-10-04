#include<bits/stdc++.h>
using namespace std;
struct svm//sirene,vreme,mi6ka
{
    long long s,v,m;
    bool operator <(const svm &x)const
    {
        if(v>x.v)return true;
        if(v<x.v)return false;
        if(s>x.s)return true;
        if(s<x.s)return false;

        return m>x.m;
    }
};
vector<svm> pq;
svm maker;
long long n,m,nz,mi6[100009],sir[100009],uk=1,cm;
bool hung[100009],si[100009];
vector<int> v;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>nz>>nz;
    for(int i=1;i<=n;i++)
    {
        cin>>mi6[i];
    }
    for(int j=1;j<=m;j++)cin>>sir[j];
    for(int i=1;i<=n;i++)
    {
        cm=100000000;
        while(abs(mi6[i]-sir[uk])<cm&&uk<=m)cm=abs(mi6[i]-sir[uk]),uk++;
        uk--;
        for(int j=uk;j<=m&&abs(mi6[i]-sir[j])==cm;j++){maker.s=j;maker.m=i;maker.v=cm;pq.push_back(maker);}
        //cout<<i<<" "<<cm<<endl;
    }
    int kaka;
    sort(pq.begin(),pq.end());
    reverse(pq.begin(),pq.end());
    //for(int i=0;i<pq.size();i++)cout<<pq[i].m<<" "<<pq[i].s<<" "<<pq[i].v<<endl;
    //cout<<endl;
    for(int i=0;i<pq.size();i++)
    {
        if(i!=0&&pq[i].v!=pq[i-1].v)
        {
            for(kaka=0;kaka<v.size();kaka++)si[v[kaka]]=1;//,cout<<v[kaka]<<" ";cout<<endl;
            v.clear();
        }
        if(hung[pq[i].m]==0&&si[pq[i].s]==0)hung[pq[i].m]=1,v.push_back(pq[i].s);

    }
    int br=0;
    for(int i=1;i<=n;i++)if(hung[i]==0)br++;
    cout<<br<<"\n";
}

