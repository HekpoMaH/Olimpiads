#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const long long inf=999999999999;
vector<pair<long long,long long> >a[10005];
long long n,m,h,g,u,v,hosp[105],used[10004],usedh[10004];
long long mn=inf;
void check(long long s)
{
    long long d[10005];
    for(int i=1;i<=n;i++)used[i]=0;
    for(int i=1;i<=n;i++)d[i]=inf;
    d[s]=0;
    long long mnv=inf,mni;
    long long node,len;
    //cout<<used[s]<<endl;
    for(int i=1;i<=n;i++)
    {
        mnv=inf;
        for(int j=1;j<=n;j++)
        {
            if(used[j]==0&&d[j]<mnv){mnv=d[j];mni=j;}
        }
        //cout<<"mni="<<mni<<" mnv="<<mnv<<endl;
        for(int j=0;j<(int)a[mni].size();j++)
        {
            node=a[mni][j].first;
            len=a[mni][j].second;
            //cout<<"d["<<mni<<"]="<<d[mni]<<" d["<<node<<"]="<<d[node]<<"<->"<<d[mni]+len<<endl;
            d[node]=min(d[mni]+len,d[node]);
        }
        used[mni]=1;
        /*for(int i=1;i<=n;i++)
        {
            cout<<"d["<<i<<"]="<<d[i]<<" ";
            //if(!usedh[i])sum+=d[i];
        }cout<<endl;*/
    }
     
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        //cout<<"d["<<i<<"]="<<d[i]<<" ";
        if(!usedh[i])sum+=d[i];
    }//cout<<endl;
    if(sum<mn)mn=sum;//cout<<"%%RD"<<endl;
}
int main()
{
    scanf("%I64d%I64d%I64d",&n,&m,&h);
    for(long long i=1;i<=h;i++){scanf("%I64d",&hosp[i]);usedh[hosp[i]]=1;}
    for(long long i=1;i<=m;i++)
    {
        scanf("%I64d%I64d%I64d",&u,&v,&g);
        //used[u]=used[v]=1;
        a[u].push_back(pair<long long,long long>(v,g));
//        k=make_pair(u,g);
        a[v].push_back(pair<long long,long long>(u,g));
    }
    for(long long i=1;i<=h;i++)
    {
        check(hosp[i]);
    }
    printf("%I64d\n",mn);
    return 0;
}