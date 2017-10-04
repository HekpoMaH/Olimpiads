#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
using namespace std;
struct point
{
    int x,y;
};
string a[55];
point prince[8];
point e,iz;
const int inf=9999999;
int n,m,ans=inf,l,princesize;
bool cmp(point a,point b)
{
    if(a.x<b.x)return true;
    if(a.x>b.x)return false;
    if(a.y<b.y)return true;
    return false;
}
int bfss(point beg,point endd)
{
    queue<point> q;
    point qn,current;
    int used[55][55],mused[55][55];
    int cx[4]={0,0,-1,1},cy[4]={-1,1,0,0};
    memset(used,0,sizeof(used));
    memset(mused,0,sizeof(mused));
    used[beg.x][beg.y]=1;
    q.push(beg);
    while(!q.empty())
    {
        current=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            qn=current;
            qn.x=(qn.x+cx[i]+n)%n;
            qn.y=(qn.y+cy[i]+m)%m;
            if(used[qn.x][qn.y]==0&&a[qn.x][qn.y]=='.')
            {
                mused[qn.x][qn.y]=mused[current.x][current.y]+1;
                used[qn.x][qn.y]=1;
                q.push(qn);
            }
            if(qn.x==endd.x&&qn.y==endd.y)return mused[endd.x][endd.y];
        }
    }
    return inf;
}
void solve()
{
    int cans=0,c,ps=princesize;
    c=bfss(e,prince[0]);
    if(c==inf){l=1;cout<<-1<<endl;return;}
    cans+=c;
    for(int i=0;i<ps-1;i++)
    {
        c=bfss(prince[i],prince[i+1]);
        if(c==inf){l=1;cout<<-1<<endl;return;}
        cans+=c;
    }
    c=bfss(prince[ps-1],iz);
    if(c==inf){l=1;cout<<-1<<endl;return;}
    cans+=c;
    if(cans<ans)ans=cans;
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]=='P'){a[i][j]='.';prince[princesize].x=i;prince[princesize].y=j;princesize++;}
            if(a[i][j]=='E'){a[i][j]='.';e.x=i;e.y=j;}
            if(a[i][j]=='X'){a[i][j]='.';iz.x=i;iz.y=j;}
        }
    }
    if(princesize==0)
    {
        ans=bfss(e,iz);
        if(ans==inf){cout<<-1<<endl;return 0;}
        cout<<ans<<endl;
        return 0;
    }
    sort(prince,prince+princesize,cmp);
    //cout<<"eli="<<e.x<<" "<<e.y<<endl;
    do
    {
        solve();
        if(l==1)return 0;
    }while(next_permutation(prince,prince+princesize,cmp));
    cout<<ans<<endl;
    return 0;
}
