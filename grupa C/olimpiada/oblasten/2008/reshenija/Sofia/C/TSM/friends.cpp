#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

vector<int> a[2048];
int d[2048], team[2048];

int bfs(int j)
{
    int i, v;
    d[j]=1;
    queue<int> dat;
    dat.push(j);
    while(!dat.empty())
    {
        v=dat.front(); dat.pop();
        for(i=0; i<a[v].size(); i++) if(!d[ a[v][i] ])
        {
            dat.push(a[v][i]);
            d[ a[v][i] ]=d[v]+1;
            team[ d[v]+1 ]++;
        }
    }
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int p, q;
    for(int i=0; i<m; i++)
    {
        scanf("%d%d", &p, &q);
        //p=rand()%n; q=rand()%n; randnumgen
        a[p].push_back(q);
        a[q].push_back(p);
    }
    bfs(1);
    int max=0;
    for(int i=1; i<2048; i++) if(team[i]>max) max=team[i];
    printf("%d\n", max);
    return 0;
}
