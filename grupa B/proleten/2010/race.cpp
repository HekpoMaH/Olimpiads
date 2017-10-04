#include<bits/stdc++.h>
using namespace std;
const int nmax=509;
const int kmax=12;
const int inf=1e9;
struct point
{
    int x,y,t;
};
int ans[nmax][kmax],used[nmax][kmax];
int numteams,numtasks,mintasks;
point final,teams[nmax],tasks[nmax];
int calct(point a,point b)
{
    return abs(a.x-b.x)+abs(a.y-b.y)+b.t;
}
void solve()
{
    memset(used,0,sizeof(used));
    memset(ans,31,sizeof(ans));
    for(int i=1;i<=numtasks;i++)
    {
        ans[i][mintasks-1]=calct(final,tasks[i]);
    }
    while(1)
    {
        int best=inf,to=-1,rem=-1;
        for(int i=1;i<=numtasks;i++)
        {
            for(int c=1;c<mintasks;c++)
            {
                if(used[i][c]==0&&best>ans[i][c])
                {
                    best=ans[i][c];
                    to=i;
                    rem=c;
                }
            }
        }
        if(best>=inf)break;
        used[to][rem]=1;
        for(int i=1;i<=numtasks;i++)
        {
            if(i!=to)
            {
                if(best+calct(tasks[to],tasks[i])<ans[i][rem-1])ans[i][rem-1]=best+calct(tasks[to],tasks[i]);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>numteams>>mintasks;
    for(int i=1;i<=numteams;i++)
    {
        teams[i].t=0;
        cin>>teams[i].x>>teams[i].y;
    }
    cin>>numtasks;
    for(int i=1;i<=numtasks;i++)
    {
        cin>>tasks[i].x>>tasks[i].y>>tasks[i].t;
    }
    cin>>final.x>>final.y;
    solve();
    for(int i=1;i<=numteams;i++)
    {
        int best=inf;
        for(int c=1;c<=numtasks;c++)
        best=min(best,ans[c][0]+calct(tasks[c],teams[i]));
        cout<<best<<"\n";
    }
}
