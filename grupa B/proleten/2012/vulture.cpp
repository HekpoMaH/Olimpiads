#include<bits/stdc++.h>
using namespace std;
int n,m,hmax,k;
const int nmax=359;
int dirx[6]={0,1,-1,0,0};
int diry[6]={0,0,0,1,-1};
struct pole
{
    int xc,yc,hc;
    pole (){}
    pole (int _xc,int _yc,int _hc)
    {
        xc=_xc;
        yc=_yc;
        hc=_hc;
    }
};
int used[nmax][nmax][51];
int h[nmax][nmax];
int v[nmax][nmax],si,sj,ei,ej;
void read()
{
    cin>>m>>n>>k>>hmax;
    for(int j=1;j<=m;j++)
    {
        for(int i=1;i<=n;i++)
        {
            //cout<<i<<" "<<j<<"\n";
            cin>>h[i][j]>>v[i][j];
        }
    }
    //for(int i=1;i<=n;i++){
    //   for(int j=1;j<=m;j++){
    //     cout<<h[i][j]<<" ";
    //   }
    //   cout<<endl;
    //}
    //cout<<endl;
    //for(int i=1;i<=n;i++){
    //   for(int j=1;j<=m;j++){
    //     cout<<v[i][j]<<" ";
    //   }
    //   cout<<endl;
    //}
    cin>>si>>sj>>ei>>ej;
}
void bfsit()
{
    used[si][sj][h[si][sj]]=1;
    queue<pole> q;
    q.push(pole(si,sj,h[si][sj]));
    pole cur;
    while(!q.empty())
    {
        cur=q.front();
        q.pop();
        for(int i=1;i<=4;i++)
        {
            pole nxt(cur.xc+dirx[i],cur.yc+diry[i],cur.hc+v[cur.xc][cur.yc]-k);
            if((!(nxt.xc>=1&&nxt.xc<=n&&nxt.yc>=1&&nxt.yc<=m))||used[nxt.xc][nxt.yc][nxt.hc])continue;
            if(nxt.xc==ei&&nxt.yc==ej&&nxt.hc==h[ei][ej])
            {
                used[nxt.xc][nxt.yc][nxt.hc]=used[cur.xc][cur.yc][cur.hc]+1;
                q.push(nxt);
                //continue;
            }
            if(nxt.hc>h[nxt.xc][nxt.yc]&&nxt.hc<=hmax+h[nxt.xc][nxt.yc])
            {
                used[nxt.xc][nxt.yc][nxt.hc]=used[cur.xc][cur.yc][cur.hc]+1;
                q.push(nxt);
            }
        }
    }
    //cout<<used[ei][ej][h[ei][ej]]<<"\n";
    if(used[ei][ej][h[ei][ej]]==0)cout<<"crash\n";
    else cout<<used[ei][ej][h[ei][ej]]-1<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    read();
    bfsit();
}

