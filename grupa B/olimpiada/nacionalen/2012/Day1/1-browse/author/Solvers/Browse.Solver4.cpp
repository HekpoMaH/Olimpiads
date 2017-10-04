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
#define EPS 0.0000001
using namespace std;

struct Point
{
    double x, y;
};

int n, m, k;
Point a[MAX], b[MAX];
double pdist[MAX][MAX];


// Push-Relabel Flow -->
// ============================

template <class Type> class Flow
{
	public:

	struct Edge
	{
		Type cap;
		int to, next;
		Edge(int to_ = 0, Type cap_ = 0, int next_ = -1) {to = to_; cap = cap_; next = next_;}
	};
	
	int numNodes;
	int globalRelabel;
	vector <int> first;
	vector <Edge> edges;
	
	vector <int> height;
	vector <Type> excess;
	
	void init(int n)
	{
		numNodes = n;
		globalRelabel = 0;
		
		first.clear(); first.resize(n, -1);
		excess.clear(); excess.resize(n, 0);
		height.clear(); height.resize(n, 0);
	}
	
	void addEdge(int from, int to, Type cap)
	{
		edges.push_back(Edge(to, cap, first[from]));
		first[from] = (int)edges.size() - 1;
		
		edges.push_back(Edge(from, 0, first[to]));
		first[to] = (int)edges.size() - 1;
	}
	
	void updateGraph(int source, int sink)
	{
		globalRelabel = 0;		
		queue <int> curQueue, nextQueue;

		for (int i = 0; i < (int)height.size(); i++)
			height[i] = -1;
		height[source] = numNodes; height[sink] = 0;
		
		curQueue.push(sink);
		while (!curQueue.empty())
		{
			while (!curQueue.empty())
			{
				int cur = curQueue.front(); curQueue.pop();
				for (int idx = first[cur]; idx != -1; idx = edges[idx].next)
				{
					if (edges[idx ^ 1].cap > 0 && height[edges[idx].to] == -1)
					{
						height[edges[idx].to] = height[cur] + 1;
						nextQueue.push(edges[idx].to);
					}
				}
			}
			swap(curQueue, nextQueue);
		}
		
		curQueue.push(source);
		while (!curQueue.empty())
		{
			while (!curQueue.empty())
			{
				int cur = curQueue.front(); curQueue.pop();
				for (int idx = first[cur]; idx != -1; idx = edges[idx].next)
				{
					if (edges[idx ^ 1 ].cap > 0 && height[edges[idx].to] == -1)
					{
						height[edges[idx].to] = height[cur] + 1;
						nextQueue.push(edges[idx].to);
					}
				}
			}
			swap(curQueue, nextQueue);
		}
	}
	
	Type findFlow(int source, int sink)
	{
		height[source] = numNodes;
		height[sink] = 0;
		
		queue <int> q;
		for (int idx = first[source]; idx != -1; idx = edges[idx].next)
		{
			if (height[edges[idx].to] == 0 && edges[idx].cap > 0)
			{
				if (edges[idx].to != source && edges[idx].to != sink)
					q.push(edges[idx].to);
				excess[edges[idx].to] += edges[idx].cap;
				edges[idx ^ 1].cap += edges[idx].cap;
				edges[idx].cap = 0;
			}
		}
		
		while(!q.empty())
		{
			int cur = q.front(); q.pop();
			if (globalRelabel++ >= numNodes * 2) updateGraph(source, sink);
			
			int next = -1;
			for (int idx = first[cur]; idx != -1; idx = edges[idx].next)
			{
				if (edges[idx].cap > 0)
				{
					if (height[edges[idx].to] == height[cur] - 1)
						{next = idx; break;}
					if (height[edges[idx].to] >= height[cur])
					{
						if (next == -1) next = idx;
						else if (height[edges[next].to] > height[edges[idx].to]) next = idx;
					}
				}
			}
			if (next == -1) continue;
			if (height[edges[next].to] > height[cur] - 1)
				height[cur] = height[edges[next].to] + 1;
			
			Type flow = min(excess[cur], edges[next].cap);
			excess[edges[next].to] += flow;
			excess[cur] -= flow;
			edges[next].cap -= flow;
			edges[next ^ 1].cap += flow;
	
			if (excess[cur] > 0) q.push(cur);
			if (edges[next].to != source && edges[next].to != sink && excess[edges[next].to] == flow)
				q.push(edges[next].to);
		}
		return excess[sink];
	}
};

// ============================
// <-- End of Push-Relabel Flow


bool eval(double maxDist)
{
	Flow <int> flow;
	flow.init(n + m + 2);
	
    for (int i = 0; i < n; i++)
        flow.addEdge(n + m, i, 1);
    for (int i = 0; i < m; i++)
        flow.addEdge(n + i, n + m + 1, k);
    for (int i = 0; i < n; i++)
        for (int c = 0; c < m; c++)
            if (pdist[i][c] < maxDist + EPS)
                flow.addEdge(i, n + c, 1);
    int ans = flow.findFlow(n + m, n + m + 1);
    return ans == n;
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

	/*
    sprintf(inpFile, "Browse.%02d.sol", testNum);
    in = fopen(inpFile, "rt");
    double real;
    fscanf(in, "%lf", &real);
    if (fabs(real - ans) < 0.000001)
    	fprintf(stderr, "Answers match.\n");
    else
    	fprintf(stderr, "Answers are different (%.6lf vs %.6lf)\n", ans, real);
    */
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
