#include <iostream>
#include <queue>
using namespace std;
queue<int>q;
bool g[2000][2000],used[2000]; 
int levels[2001],maxt=0;
int N,M;
void bfs(int i)
{
    used[i]=1; levels[i]++; if(maxt<levels[i]) maxt=levels[i];
    q.push(i);
    while(!q.empty())
    {
        for(int j=0;j<N;j++)
         if(g[i][j] && !used[j]) { used[j]=1; q.push(j); levels[levels[i]+1]=levels[levels[i]+1]+1;
                                   if(maxt<levels[levels[i]+1]) maxt=levels[levels[i]+1]+1;
                                 }
        if(!q.empty()) { q.pop(); i=q.front(); }
    }
} 
int main()
{
    int a,b;
    cin >> N >> M;
    for(int i=0;i<M;i++)
    {
        cin >> a >> b;
        g[a-1][b-1]=g[b-1][a-1]=1;
    }
    bfs(0);
    cout << maxt << endl;
    return 0;
}
