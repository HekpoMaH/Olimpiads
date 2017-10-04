#include<cstdio>
#include<set>
#include<map>
#include<queue>
using namespace std;
const int dx[] = {1, 1, 1, 0, -1, -1, -1, 0};
const int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int n,x0,y0,x1,y1;
map<pair<int,int>, long long> dist;
int cnt;
set<pair<int,int> > allowed;
queue< pair<int,int> > q;
int main()
{
    scanf("%d%d%d%d",&x0,&y0,&x1,&y1);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int r,a,b;
        scanf("%d%d%d",&r,&a,&b);
        for(int j=a;j<=b;j++)allowed.insert(make_pair(r,j));
    }
    q.push(make_pair(x0,y0));
    dist[make_pair(x0,y0)]=0;
    while(!q.empty())
    {
        int currx=q.front().first;
        int curry=q.front().second;

        long long d=dist[q.front()];if(currx==x1&&curry==y1){printf("%I64d",d);return 0;}
        q.pop();
        for(int i=0;i<8;i++)
        {
            int nx=currx+dx[i];
            int ny=curry+dy[i];
            if(allowed.find(make_pair(nx, ny)) != allowed.end())
            {
                if(dist.count(make_pair(nx,ny))!=0)continue;
                dist[make_pair(nx,ny)]=d+1;
                q.push(make_pair(nx,ny));
            }
        }
    }
    printf("-1");
    return 0;
}
