/*
ID: espr1t
LANG: C++
TASK: Browse
KEYWORDS: Solver
*/

#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 1024
using namespace std;

struct Point
{
    double x, y;
};

int n, m, k;
Point a[MAX], b[MAX];
double pdist[MAX][MAX];


#define MAX_NODES 1024
#define INF 999666333
#define EPS 0.000001

vector <int> v[MAX_NODES];
int ma3x[MAX_NODES][MAX_NODES];
int vis[MAX_NODES], last[MAX_NODES], flow[MAX_NODES];

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

void solveTest(int testNum)
{
    char inpFile[32], outFile[32];
    sprintf(inpFile, "Browse.%02d.in", testNum);
    sprintf(outFile, "Browse.%02d.out", testNum);
    FILE* in = fopen(inpFile, "rt");
    FILE* out = fopen(outFile, "wt");

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
    fprintf(stderr, "Distances size is: %d\n", (int)distances.size());
    
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
    fclose(in); fclose(out);
    
    sprintf(inpFile, "Browse.%02d.sol", testNum);
    in = fopen(inpFile, "rt");
    double real;
    fscanf(in, "%lf", &real);
    if (fabs(real - ans) < 0.000001)
    	fprintf(stderr, "Answers match.\n");
    else
    	fprintf(stderr, "Answers are different (%.6lf vs %.6lf)\n", ans, real);    
}

int main(void)
{
    int numTests = 20;
    for (int test = 0; test <= numTests; test++)
    {
        unsigned sTime = clock();
        fprintf(stderr, "Solving test case %d...", test);
        solveTest(test);
        fprintf(stderr, " Execution time: %.3lfs.\n",
            (double)(clock() - sTime) / CLOCKS_PER_SEC);
    }
    fprintf(stderr, "Finished solving test cases.\n");
    system("pause");
    return 0;
}
