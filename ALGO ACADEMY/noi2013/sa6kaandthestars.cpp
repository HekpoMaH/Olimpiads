#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime>
#include<queue>
#include<cmath>
using namespace std;
int n,m,br;
long long used[4009][4009];
queue<pair<int,int> > q;
long long a[6][6];
long long sx,sy,ex,ey,preebanko;
int main()
{
    //clock_t ti=clock();
    ios::sync_with_stdio(false);
    cin>>sx>>sy>>ex>>ey;
    for(int i=0;i<=3;i++)for(int j=1;j<=4;j++)cin>>a[i][j];
    used[sx][sy]=1;
    q.push(make_pair(sx,sy));
    while(!q.empty()&&used[ex][ey]==0)
    {
        preebanko++;//cout<<preebanko<<endl;
        if(preebanko>10000000)break;
        pair<int,int> crr;
        crr=q.front();q.pop();
        int tp=crr.first+crr.second;
        tp%=4;
        for(int i=1;i<=4;i++)
        {
            if(crr.first-a[tp][i]>0&&used[crr.first-a[tp][i]][crr.second]==0)
            {
                q.push(make_pair(crr.first-a[tp][i],crr.second));
                used[crr.first-a[tp][i]][crr.second]=used[crr.first][crr.second]+1;
            }
            if(crr.second-a[tp][i]>0&&used[crr.first][crr.second-a[tp][i]]==0)
            {
                q.push(make_pair(crr.first,crr.second-a[tp][i]));
                used[crr.first][crr.second-a[tp][i]]=used[crr.first][crr.second]+1;
            }
            if(crr.first+a[tp][i]<=4000&&used[crr.first+a[tp][i]][crr.second]==0)
            {
                q.push(make_pair(crr.first+a[tp][i],crr.second));
                used[crr.first+a[tp][i]][crr.second]=used[crr.first][crr.second]+1;
            }
            if(crr.second+a[tp][i]<=4000&&used[crr.first][crr.second+a[tp][i]]==0)
            {
                q.push(make_pair(crr.first,crr.second+a[tp][i]));
                used[crr.first][crr.second+a[tp][i]]=used[crr.first][crr.second]+1;
            }
        }
    }//ti=clock()-ti;
    //cout<<(double)(ti/CLOCKS_PER_SEC)<<endl;
    if(used[ex][ey]==0)used[ex][ey]=16000000;
    for(int i=1;i<=4000;i++)
    {
        for(int j=1;j<=4000;j++)
        {
            if(used[i][j]!=0)
            {
                used[ex][ey]=min(used[ex][ey],used[i][j]+abs(i-ex)+abs(j-ey));
            }
        }
    }
    cout<<used[ex][ey]-1<<endl;
}


