#include<bits/stdc++.h>
using namespace std;
char v[5009][5009];
int ps[5009][5009],it[5009][5009];
int n,m;
void upd(int idx,int pos)
{
    while(pos>0)
    {
        it[idx][pos]++;
        pos-=pos&(-pos);
    }
}
int get(int idx,int pos)
{
    int re=0;
    while(pos<=5000)
    {
        re+=it[idx][pos];
        pos+=pos&(-pos);
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
        for(int j=1;j<=m;j++)
        {
            cin>>v[i][j];
            if(v[i][j]=='1')ps[i][j]=ps[i][j-1]+1;
            upd(j,ps[i][j]);
        }
    }
    int ans=0;
    int siz;
    int i;
    for(int j=1;j<=m;j++)
    {
        siz=1;
        i=1;
        while(siz!=0)
        {
            siz=get(j,i);
            ans=max(ans,siz*i);
            i++;
        }
    }
    cout<<ans<<endl;
}
