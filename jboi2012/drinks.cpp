#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
vector<pair<int,int> > route;
int r,c,mr=100*100*100;
char ch;
int t[102][102],used[102][102];
pair<int,int> start,en;
int bfs(pair<int,int> s,pair<int,int> e)
{
    queue<pair<int,int> > q;
    q.push(s);
    memset(used,0,sizeof(used));
    used[s.first][s.second]=1;
    pair<int,int> tek;
    int x,y;
    while(!q.empty())
    {
        tek=q.front();
        if(tek==e)break;
        q.pop();
        x=tek.first-1;y=tek.second;
        if(x>=1&&x<=r&&y>=1&&y<=c&&t[x][y]==0&&used[x][y]==0)
        {
            used[x][y]=used[tek.first][tek.second]+1;
            q.push(make_pair(x,y));
        }
        x=tek.first+1;y=tek.second;
        if(x>=1&&x<=r&&y>=1&&y<=c&&t[x][y]==0&&used[x][y]==0)
        {
            used[x][y]=used[tek.first][tek.second]+1;
            q.push(make_pair(x,y));
        }
        x=tek.first;y=tek.second-1;
        if(x>=1&&x<=r&&y>=1&&y<=c&&t[x][y]==0&&used[x][y]==0)
        {
            used[x][y]=used[tek.first][tek.second]+1;
            q.push(make_pair(x,y));
        }
        x=tek.first;y=tek.second+1;
        if(x>=1&&x<=r&&y>=1&&y<=c&&t[x][y]==0&&used[x][y]==0)
        {
            used[x][y]=used[tek.first][tek.second]+1;
            q.push(make_pair(x,y));
        }
    }
    return used[e.first][e.second]-1;
}
void solve()
{
    if(route.size()==0){mr=bfs(start,en);return;}
    //cout<<"ns"<<endl;
    //for(int i=0;i<route.size();i++)cout<<route[i].first<<" "<<route[i].second<<endl;
    int rl=0;
    rl+=bfs(start,route[0]);//cout<<"rl="<<rl<<endl;
    for(int i=1;i<route.size();i++)rl+=bfs(route[i-1],route[i]);//cout<<"rl="<<rl<<endl;
    rl+=bfs(route[route.size()-1],en);//cout<<"rl="<<rl<<endl;
    mr=min(rl,mr);
}
int main()
{
     cin>>r>>c;
     for(int i=1;i<=r;i++)
     {
         for(int j=1;j<=c;j++)
         {
             cin>>ch;
             if(ch=='#')t[i][j]=1;
             if(ch=='D')route.push_back(make_pair(i,j)),t[i][j]=0;
             if(ch=='S')start.first=i,start.second=j,t[i][j]=0;
             if(ch=='B')en.first=i,en.second=j,t[i][j]=0;
         }
     }
     do
     {
         //cout<<"a"<<endl;
         solve();
     }while(next_permutation(route.begin(),route.end()));
     cout<<mr<<endl;
     return 0;
}