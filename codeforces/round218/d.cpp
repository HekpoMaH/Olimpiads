#include<bits/stdc++.h>
using namespace std;
long long it[300009],it2[300009];
int n,m;
long long a[300009];
long long ps[300009];
void upd(int pos,int val)
{
    int idx=pos;
    while(idx<=200009)
    {
        it[idx]+=val;
        idx+=(-idx)&idx;
    }
}
long long get(int pos)
{
    int idx=pos;
    long long re=0;
    while(idx!=0)
    {
        re+=it[idx];
        idx-=idx&(-idx);
    }
    return re;
}
void upd2(int pos,int val)
{
    int idx=pos;
    while(idx<=200009)
    {
        it2[idx]+=val;
        idx+=(-idx)&idx;
    }
}
long long get2(int pos)
{
    int idx=pos;
    long long re=0;
    while(idx!=0)
    {
        re+=it2[idx];
        idx-=idx&(-idx);
    }
    return re;
}
int main()
{

    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ps[i]=ps[i-1]+a[i];
    }
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        long long z;
        cin>>x;
        if(x==1)
        {
            cin>>y>>z;
            upd(y,z);
        }
        else
        {
            cin>>y;
            long long obem=get(y)-get(y-1)-get2(y-1);
            if(obem<a[y])
            {
                cout<<max(0LL,obem)<<"\n";
            }
            else cout<<a[y]<<"\n",upd2(y,a[y]);
        }
    }
}
