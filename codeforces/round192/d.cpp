#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1009][1009],usedx[1009],usedy[1009],used[1009][1009];
char ch;
int l,br;
pair<int,int> st,en;
queue<pair<int,int> >q;
vector<int> ls;

void bfs()
{
    q.push(st);used[st.first][st.second]=1;
    while(!q.empty())
    {
        pair<int,int> cr=q.front();q.pop();

        if(cr.first-1>=1&&a[cr.first-1][cr.second]!=-1&&used[cr.first-1][cr.second]==0)q.push(make_pair(cr.first-1,cr.second)),used[cr.first-1][cr.second]=used[cr.first][cr.second]+1;
        if(cr.first+1<=n&&a[cr.first+1][cr.second]!=-1&&used[cr.first+1][cr.second]==0)q.push(make_pair(cr.first+1,cr.second)),used[cr.first+1][cr.second]=used[cr.first][cr.second]+1;
        if(cr.second-1>=1&&a[cr.first][cr.second-1]!=-1&&used[cr.first][cr.second-1]==0)q.push(make_pair(cr.first,cr.second-1)),used[cr.first][cr.second-1]=used[cr.first][cr.second]+1;
        if(cr.second+1<=m&&a[cr.first][cr.second+1]!=-1&&used[cr.first][cr.second+1]==0)q.push(make_pair(cr.first,cr.second+1)),used[cr.first][cr.second+1]=used[cr.first][cr.second]+1;
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>ch;
            if(ch=='E')a[i][j]=0,used[i][j]=1,st.first=i,st.second=j;
            if(ch>='0'&&ch<='9')a[i][j]=ch-'0';
            if(ch=='S')a[i][j]=0,used[i][j]=0,en.first=i,en.second=j;
            if(ch=='T')a[i][j]=-1;
            //else col[i]
        }
    }
    bfs();
    //cout<<used[1][3]<<" "<<used[1][4]<<" "<<used[1][7]<<endl;br=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]>0)
            {
                if(used[i][j]<=used[en.first][en.second]&&used[i][j]!=0)br+=a[i][j];
            }
        }
    }
    //cout<<used[4][1]<<" "<<used[3][2]<<" "<<used[5][4]<<endl;
    cout<<br<<endl;
}


