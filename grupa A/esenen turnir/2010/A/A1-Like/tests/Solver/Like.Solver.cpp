/*
ID: espr1t
TASK: like
LANG: C++
CONTEST: National Autumn Contest, Shumen 2010
AUTHOR: Alexander Georgiev
SOLUTION:
	We add fictive undirected edges to the initial ones
	in order to make the graph Eulerian (i.e. the degree of each node
	to be even). We can always do that, because there are always even
	number of nodes with odd degree in the initial graph. After doing
	this we simply run an algorithm to find Eulerian cycle(s) in the
	resulting graph. This directs the expanded graph, with the property
	that the input degree of each node equals its output degree. Since
	we've added at most one fictive edge to each node, after removing
	them we get disbalance of at most one (which is what we wanted).
NOTES:
	We use Velin's method to represent the graph (smart list of edges)
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>

#define MAX_NODES 1024
#define MAX_EDGES 131072

using namespace std;
FILE *in; FILE *out;

struct Edge
{
	int next;
	int node1, node2;
	int fictive, dir;
};

int n, m;
int start[MAX_NODES];
Edge edges[MAX_EDGES << 1]; int numEdges;

void addEdge(int node1, int node2, int fictive)
{
	for (int i = 0; i < 2; i++)
	{
		edges[numEdges].node1 = node1;
		edges[numEdges].node2 = node2;
		edges[numEdges].fictive = fictive;
		edges[numEdges].dir = -1;
		edges[numEdges].next = start[node1];
		start[node1] = numEdges++;
		node1 ^= node2 ^= node1 ^= node2;
	}
}

void euler(int node)
{
	for (int idx = start[node]; idx != -1; idx = edges[idx].next)
	{
		if (edges[idx].dir == -1)
		{
			edges[idx ^ 0].dir = 0;
			edges[idx ^ 1].dir = 1;
			euler(edges[idx].node2);
		}
	}
}

void solve()
{
	// Initialize
	numEdges = 0;
	memset(start, -1, sizeof(start));
	
	// Read input
	fscanf(in, "%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int n1, n2;
		fscanf(in, "%d %d", &n1, &n2);
		addEdge(n1 - 1, n2 - 1, 0);
	}

	// Add fictive edges
	int last = -1;
	for (int i = 0; i < n; i++)
	{
		int parity = 0;
		for (int idx = start[i]; idx != -1; idx = edges[idx].next)
			parity ^= 1;
		
		if (parity == 1)
		{
			if (last == -1) last = i;
			else
			{
				addEdge(last, i, 1);
				last = -1;
			}
		}
	}
	
	// Run Eulerian Cycle algorithm for each connected component
	for (int i = 0; i < numEdges; i++)
		if (edges[i].dir == -1) euler(edges[i].node1);
	
	fprintf(out, "Yes\n");
	for (int i = 0; i < numEdges; i++)
		if (!edges[i].fictive && edges[i].dir == 0)
			fprintf(out, "%d %d\n", edges[i].node1 + 1, edges[i].node2 + 1);
	
	return;
}

int main(void)
{
	int numTests = 20;
	for (int test = 1; test <= numTests; test++)
	{
		unsigned sTime = clock();
		char inpName[32], outName[32];
		sprintf(inpName, "Like.%02d.in", test);
		sprintf(outName, "Like.%02d.sol", test);		
		in = fopen(inpName, "rt"); out = fopen(outName, "wt");
		solve();
		fclose(in); fclose(out);
		fprintf(stderr, "Solved test nr. %d for %.3lf seconds.\n", test, (double)(clock() - sTime) / (double)CLOCKS_PER_SEC);
	}
	fprintf(stderr, "Finished solving all tests.\n");
	system("pause");
	return 0;
}

