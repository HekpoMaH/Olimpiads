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
using namespace std;
FILE* in; FILE* out;

// Dinitz Algorithm

#define MAX_NODES 1024
#define MAX_EDGES 524288
#define INF 999666333

struct Edge
{
	int next, to, cap;
	Edge(int next_ = 0, int to_ = 0, int cap_ = 0)
		{next = next_; to = to_; cap = cap_;}
};

int source, sink;
Edge edges[MAX_EDGES]; int numEdges;
int vis[MAX_NODES], dist[MAX_NODES], first[MAX_NODES];

int recurse(int node, int flow)
{
	if (node == sink) return flow;
	for (int idx = first[node]; idx != -1; idx = edges[idx].next)
	{
		if (!vis[edges[idx].to] && edges[idx].cap > 0 && dist[node] == dist[edges[idx].to] + 1)
		{
			int ret = recurse(edges[idx].to, min(flow, edges[idx].cap));
			if (ret) {edges[idx].cap -= ret; edges[idx ^ 1].cap += ret; return ret;}
		}
	}
	vis[node] = 1;
	return 0;
}

int dinitz(int source_, int sink_)
{
	source = source_; sink = sink_;
	
	int flow = 0;
	while (1)
	{
		// BFS
		int cur = 0;
		queue <int> q;

		for (int i=0; i<MAX_NODES; i++) dist[i] = MAX_NODES;
		q.push(sink); dist[sink] = 0;
		
		while (!q.empty())
		{
			cur = q.front(); q.pop();
			for (int idx = first[cur]; idx != -1; idx = edges[idx].next)
			{
				if (edges[idx ^ 1].cap > 0 && dist[edges[idx].to] == MAX_NODES)
				{
					dist[edges[idx].to] = dist[cur] + 1;
					q.push(edges[idx].to);
					if (edges[idx].to == source) {cur = source; break;}
				}
			}
			if (cur == source) break;
		}
		if (cur != source) break;
		
		// DFS
		int flag = 0;
		memset(vis, 0, sizeof(vis));
		while(1)
		{
			int add = recurse(source, INF);
			if (add == 0) break;
			flow += add; flag = 1;
		}
		if (!flag) break;
	}
	return flow;
}

inline void addEdge(int from, int to, int cap)
{
	if (!numEdges) memset(first, -1, sizeof(first));
	edges[numEdges].to = to; edges[numEdges].cap = cap;
	edges[numEdges].next = first[from]; first[from] = numEdges++;
	
	edges[numEdges].to = from; edges[numEdges].cap = 0;
	edges[numEdges].next = first[to]; first[to] = numEdges++;
}

// End of Dinitz Algorithm


struct Point
{
    double x, y;
};

int n, m, k;
Point a[MAX], b[MAX];
double pdist[MAX][MAX];

bool eval(double maxDist)
{
    numEdges = 0;
    memset(first, -1, sizeof(first));
    for (int i = 0; i < n; i++)
        addEdge(n + m, i, 1);
    for (int i = 0; i < m; i++)
        addEdge(n + i, n + m + 1, k);
    for (int i = 0; i < n; i++)
        for (int c = 0; c < m; c++)
            if (pdist[i][c] <= maxDist)
                addEdge(i, n + c, 1);
    int flow = dinitz(n + m, n + m + 1);
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
