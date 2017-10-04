#include<bits/stdc++.h>
using namespace std;
int n,m,l[300009],r[300009];
int it[1000009];
int br,x[300009];
void upd(int pos)
{
    while(pos<=1000009)
    {
        it[pos]++;
        pos+=pos&(-pos);
    }
}
int get(int pos)
{
    int re=0;
    while(pos!=0)
    {
        re+=it[pos];
        pos-=pos&(-pos);
    }
    return re;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>l[i]>>r[i];
    }
    for(int i=1;i<=m;i++)
    {
        cin>>br;
        int afq=0;
        memset(it,0,sizeof(it));
        for(int j=1;j<=br;j++)cin>>x[j],upd(x[j]);
        for(int j=1;j<=n;j++)
        {
            //cout<<"j="<<j<<endl;
            if(get(r[j])-get(l[j]-1)>0)afq++;
        }
        cout<<afq<<"\n";
    }
}
