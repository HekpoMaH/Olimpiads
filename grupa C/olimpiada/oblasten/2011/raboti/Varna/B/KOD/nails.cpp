#include <iostream>
using namespace std;

#define MAXN 1005

struct dot{
    int x, y;
};

struct line{
    dot a, b;
};

int ans, n = 0;
bool graph[MAXN][MAXN], used[MAXN];
line nails[MAXN];//nails[n] is the cable

double det(const dot &a, const dot &b, const dot &c)
{
    return a.x*b.y + a.y*c.x + b.x*c.y - a.x*c.y - a.y*b.x - b.y*c.x;
}

bool crossed(const line &a, const line &b)
{
    if(det(a.a, a.b, b.a) * det(a.a, a.b, b.b) <= 0)//on different sides
        if(det(b.a, b.b, a.a) * det(b.a, b.b, a.b) <= 0)
            return true;
    return false;
}

void DFS(const int &node)
{
    ans--;
    used[node] = true;

    for(int i = 0;i < n;i++)
        if(graph[node][i] && !used[i])
            DFS(i);
}

int main()
{
    memset(&graph, false, sizeof(graph));
    memset(&used, false, sizeof(used));

    while(!cin.eof())
    {
        cin >> nails[n].a.x >> nails[n].a.y >> nails[n].b.x >> nails[n].b.y;
        n++;
    }
    n--;
    ans = n;

    int i, j;
    for(i = 0;i < n;i++)
        for(j = i+1;j < n;j++)
            if(crossed(nails[i], nails[j]))
            {
                graph[i][j] = graph[j][i] = true;
                //cout << i + 1 << " and " << j + 1 << endl;
            }

    DFS(n-1);

    cout << ans << endl;

    return 0;
}
