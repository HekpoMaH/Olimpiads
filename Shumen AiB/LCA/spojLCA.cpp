#include<bits/stdc++.h>
using namespace std;
int vr[3009],c[2009],l[3009],used[2009],brvr,m[2009][25];
int n,mm,brt;
vector<int> v[2009];
void read()
{
    cin>>n;
    int x,y;
    for(int i=1;i<=n;i++)v[i].clear();
    for(int i=1;i<=n;i++)
    {
        cin>>mm;
        for(int j=1;j<=mm;j++)cin>>x,v[i].push_back(x);
    }
    cin>>mm;
}
void dfsit(int node,int level)
{
    //cout<<node<<" "<<level<<endl;
    used[node]=1;
    brvr++;
    vr[brvr]=node;
    l[brvr]=level;
    for(int i=0;i<v[node].size();i++)
    {
        if(used[v[node][i]]==0)
        {
            dfsit(v[node][i],level+1);
            vr[++brvr]=node;
            l[brvr]=level;
        }
    }
}
void makec()
{
    for(int i=1;i<=brvr;i++)
    {
        if(c[vr[i]]==0)c[vr[i]]=i;
        //cout<<i<<" "<<vr[i]<<endl;
    }
}
void makermq()
{
    for(int i=1;i<=brvr;i++)
    m[i][0]=i;
    //cout<<(1<<1)<<" "<<(1<<2)<<" "<<(1<<3)<<endl;
    for(int j=1;1<<j <=brvr;j++)
    {
        for(int i=1;i+(1<<j)-1<=brvr;i++)
        {
            //cout<<(1<<(j-1))<<endl;
            if(l[m[i][j-1]]<l[m[i+(1<<(j-1))][j-1]])m[i][j]=m[i][j-1];
            else m[i][j]=m[i+(1<<(j-1))][j-1];
        }
    }
}
int ans(int a,int b)
{
    int sz=abs(b-a)+1;
    int br=0;
    do
    {
        br++;
    }while((1<<(br))<=sz);
    if(1<<br>sz)br--;
    if(l[m[a][br]]<=l[m[b-(1<<br)+1][br]])return vr[m[a][br]];
    else return vr[m[b-(1<<br)+1][br]];
}
void qryit()
{
    int x,y;
    ios_base::sync_with_stdio(false);cin.tie(0);
    cout<<"Case "<<brt<<":\n";
    for(int i=1;i<=mm;i++)
    {
        cin>>x>>y;
        cout<<ans(min(c[x],c[y]),max(c[x],c[y]))<<"\n";
    }
}
int main()
{
    int t=0;
    cin>>t;
    while(t--)
    {
        brt++;
        memset(used,0,sizeof(used)),memset(c,0,sizeof(c));
        memset(vr,0,sizeof(vr)),memset(m,0,sizeof(m));
        memset(l,0,sizeof(l));brvr=0;
        read();
        dfsit(1,0);
        makec();
        makermq();
        //cout<<"mm="<<mm<<endl;
        qryit();
    }

}
/*
13
1 2
1 3
1 4
3 5
3 6
3 7
6 8
6 9
7 10
7 11
10 12
10 13
*/


