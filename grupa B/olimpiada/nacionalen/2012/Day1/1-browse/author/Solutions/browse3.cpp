/*
ID: espr1t
LANG: C++
TASK: Browse
KEYWORDS: Medium, Binary Search, Flow
*/

#include <cmath>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX 1024
#define EPS 0.00000001
#define INF 999666333

using namespace std;
FILE* in; FILE* out;

struct Point
{
    double x, y;
};

int n, m, k;
Point a[MAX], b[MAX];
double pdist[MAX][MAX];

vector <int> v[MAX];
int ma3x[MAX][MAX];
int vis[MAX], last[MAX], flow[MAX];

int maxFlow(int SOURCE, int SINK)
{
	int ans = 0;
	int cur, next;

	while (1)
	{
		memset(vis, 0, sizeof(vis));
		memset(last, -1, sizeof(last));
		memset(flow, 0, sizeof(flow));
		
		queue <int> q;
		q.push(SOURCE); vis[SOURCE] = 1; last[SOURCE] = -1; flow[SOURCE] = INF;
		
		while (!q.empty())
		{
			cur = q.front(); q.pop();			

			for (int i=0; i<(int)v[cur].size(); i++) if (!vis[v[cur][i]])
			{
				next = v[cur][i];
				if (ma3x[cur][next] <= 0) continue;
				if (flow[next] < min(flow[cur], ma3x[cur][next]))
				{
					flow[next] = min(flow[cur], ma3x[cur][next]);
					last[next] = cur; vis[next] = 1; q.push(next);
				}
				if (next == SINK) {cur = next; break;}
			}
			if (cur == SINK) break;
		}
		if (cur != SINK) break;
		else ans += flow[SINK];
		
		while (last[cur] != -1)
		{
			ma3x[last[cur]][cur] -= flow[SINK];
			ma3x[cur][last[cur]] += flow[SINK];
			cur = last[cur];
		}
	}
	return ans;
}

void addEdge(int from, int to, int cap)
{
	v[from].push_back(to);
	v[to].push_back(from);
	ma3x[from][to] += cap;
}

bool eval(double maxDist)
{
	for (int i = 0; i < n + m + 2; i++)
		v[i].clear();
	memset(ma3x, 0, sizeof(ma3x));
	
    for (int i = 0; i < n; i++)
        addEdge(n + m, i, 1);
    for (int i = 0; i < m; i++)
        addEdge(n + i, n + m + 1, k);
    for (int i = 0; i < n; i++)
        for (int c = 0; c < m; c++)
            if (pdist[i][c] < maxDist + EPS)
                addEdge(i, n + c, 1);
    int flow = maxFlow(n + m, n + m + 1);    
    return flow == n;
}

int main(void)
{
    in = stdin; out = stdout;
//    in = fopen("Browse.in", "rt"); out = fopen("Browse.out", "wt");

    fscanf(in, "%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++)
        fscanf(in, "%lf %lf", &a[i].x, &a[i].y);
    for (int i = 0; i < m; i++)
        fscanf(in, "%lf %lf", &b[i].x, &b[i].y);
    
    for (int i = 0; i < n; i++)
    	for (int c = 0; c < m; c++)
    		pdist[i][c] = sqrt((a[i].x - b[c].x) * (a[i].x - b[c].x) +
    						   (a[i].y - b[c].y) * (a[i].y - b[c].y));
    
    vector <double> distances;
    for (int i = 0; i < n; i++)
    	for (int c = 0; c < m; c++)
    		distances.push_back(pdist[i][c]);
    sort(distances.begin(), distances.end());
    distances.resize(unique(distances.begin(), distances.end()) - distances.begin());
    
    double ans = distances.back();
    int left = 0, right = (int)distances.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (eval(distances[mid]))
            ans = min(ans, distances[mid]), right = mid - 1;
        else left = mid + 1;
    }
    fprintf(out, "%.6lf\n", ans);
    return 0;
}
