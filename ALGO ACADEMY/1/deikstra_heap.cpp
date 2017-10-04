#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int,int> pii;
const long long inf=999999999999;
vector<pii>a[10005];
long long n,m,h,g,u,v;
bool usedh[10004];
long long mn=inf;
long long d[10005],pred[10005];
priority_queue<pii, vector<pii>, greater<pii> > pq;
void check(long long s)
{
    
    //for(int i=1;i<=n;i++)used[i]=0;
    for(int i=1;i<=n;i++)d[i]=inf;
    d[s]=0;
    pred[s]=-1;
    pii current;
    //while(pq.size())pq.pop();
    pq.push(make_pair(0,s));
    long long node,len,node2,len2;
    while(pq.size())
    {
        current=pq.top();
        pq.pop();
        len=current.first;
        node=current.second;
        //cout<<len<<endl;
        if(d[node]<len)continue;
        d[node]=len;
        for(int i=0;i<a[node].size();i++)
        {
            len2=a[node][i].second;
            node2=a[node][i].first;
            if(d[node2]>len+len2)
            {
                d[node2]=len+len2;
                pred[node2]=node;
                pq.push(make_pair(len+len2,node2));
            }
        }
    }
    
    long long sum=0;
    for(int i=1;i<=n;i++)
    {
        //cout<<"d["<<i<<"]="<<d[i]<<" ";
        if(!usedh[i])sum+=d[i];
    }//cout<<endl;
    if(sum<mn)mn=sum;//cout<<"%%RD"<<endl;
    int k=n;
    while(k!=-1)
    {
        cout<<"k="<<k<<endl;
        k=pred[k];
    }
}
int main()
{
    scanf("%I64d%I64d%I64d",&n,&m,&h);
    long long damn;
    //for(long long i=1;i<=h;i++){scanf("%I64d",&damn);usedh[damn]=1;}
    for(long long i=1;i<=m;i++)
    {
        scanf("%I64d%I64d%I64d",&u,&v,&g);
        //used[u]=used[v]=1;
        a[u].push_back(make_pair(v,g));
//        k=make_pair(u,g);
        a[v].push_back(make_pair(u,g));
    }
    check(1);
    printf("%I64d\n",d[n]);
    return 0;
}
/*
5 8 2
1 2 5
4 1 2
1 3 1
3 4 4
4 5 1
2 4 3
5 2 1
2 3 20
*/