/*
ID: espr1t
LANG: C++
TASK: Company Testgen
COMP: Autumn National Contest, 2011
KEYWORDS: Graph, Tree, Recursion
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 262144

int random()
{
	return (((rand() & ((1 << 15) - 1)) << 16) | (rand() & ((1 << 16) - 1)));
}

int n;
int parent[MAX], indices[MAX];

void randomizeIndices(int numNodes)
{
	for (int i = 1; i <= numNodes; i++)
		indices[i] = i;
	random_shuffle(indices + 2, indices + numNodes);
}

void sampleTest1()
{
	n = 6;
	int parents[5] = {1, 4, 1, 2, 4};
	for (int i = 0; i < 5; i++) parent[i + 2] = parents[i];
}

void sampleTest2()
{
	n = 14;
	int parents[13] = {1, 1, 2, 2, 2, 3, 3, 1, 9, 9, 10, 10, 11};
	for (int i = 0; i < 13; i++) parent[i + 2] = parents[i];
}

void randomTest(int numNodes)
{
	randomizeIndices(numNodes);

	n = numNodes;
	for (int i = 2; i <= numNodes; i++)
		parent[indices[i]] = indices[random() % (i - 1) + 1];
}

void shortTree(int numNodes)
{
	randomizeIndices(numNodes);

	n = numNodes;
	for (int i = 2; i <= numNodes; i++)
		parent[indices[i]] = indices[std::min(i - 1, random() % (random() % i + 1) + 1)];
	for (int i = 0; i < numNodes / 2; i++)
		parent[indices[50 + random() % std::max(1, (numNodes - 50))]] = indices[42];
}

void flatTree(int numNodes)
{
	randomizeIndices(numNodes);

	n = numNodes;
	parent[indices[2]] = indices[1];
	parent[indices[3]] = indices[1];
	for (int i = 4; i < numNodes; i++)
		parent[indices[i]] = indices[2];
	parent[indices[numNodes]] = indices[numNodes - 2];
}

void simpleLine(int numNodes)
{
	n = numNodes;
	for (int i = 2; i <= n; i++)
		parent[i] = i - 1;
}

void shardedLine(int numNodes)
{
	n = numNodes;
	for (int i = 2; i <= n; i++)
		parent[i] = std::max(1, i - rand() % 2 - 1);
}

void printTest(int test)
{
	fprintf(stderr, "Printing test %d\n", test);
	char fileName[32];
	sprintf(fileName, "Company.%02d.in", test);
	FILE* out = fopen(fileName, "wt");
	
	randomizeIndices(n);
	fprintf(out, "%d\n", n);
	for (int i = 2; i <= n; i++)
		fprintf(out, "%d %d\n", parent[indices[i]], indices[i]);
	
//	fprintf(out, "%d\n");
//	for (int i = 2; i <= n; i++)
//		fprintf(out, "%d%c", parent[i], i == n ? '\n' : ' ');
	fclose(out);
	
	int maxHeight = 0;
	int maxChildren = 0;
	static int height[MAX];
	static std::vector<int> v[MAX];
	
	memset(height, -1, sizeof(height));
	for (int i = 0; i <= n; i++) v[i].clear();

	for (int i = 2; i <= n; i++)
		v[parent[i]].push_back(i);
	
	// This BFS will fail if graph is not a tree
	std::queue <int> q;
	q.push(1); height[1] = 0;
	while (!q.empty())
	{
		int node = q.front(); q.pop();
		for (int i = 0; i < (int)v[node].size(); i++)
		{
			height[v[node][i]] = height[node] + 1;
			q.push(v[node][i]);
		}
	}
	
	for (int i = 1; i <= n; i++)
	{
		maxHeight = std::max(maxHeight, height[i]);
		maxChildren = std::max(maxChildren, (int)v[i].size());
	}
		
	fprintf(stderr, "Info for test %02d:\n", test);
	fprintf(stderr, "  >> Number of nodes: %d\n", n);
	fprintf(stderr, "  >> Max height of the tree: %d\n", maxHeight);
	fprintf(stderr, "  >> Max number of children: %d\n", maxChildren);
	fprintf(stderr, "========================================\n");
}


int main(void)
{
	srand(42);
	int numTests = 20;
	for (int test = 0; test <= numTests; test++)
	{
		fprintf(stderr, "Generating test %d\n", test);
		if (test == 0) sampleTest1();
		else if (test == 1) sampleTest2();
		else if (test == 2) randomTest(20);
		else if (test == 3) randomTest(50);
		else if (test == 4) randomTest(70);
		else if (test == 5) randomTest(100);
		else if (test == 6) randomTest(300);
		else if (test == 7) shortTree(500);
		else if (test == 8) randomTest(800);
		else if (test == 9) randomTest(1000);
		else if (test == 10) randomTest(2000);
		else if (test == 11) randomTest(3000);
		else if (test == 12) flatTree(5000);
		else if (test == 13) simpleLine(10000);
		else if (test == 14) shardedLine(10000);
		else if (test == 15) randomTest(50000);
		else if (test == 16) flatTree(80000);
		else if (test == 17) shortTree(100000);
		else if (test == 18) shardedLine(150000);
		else if (test == 19) simpleLine(200000);
		else if (test == 20) shardedLine(200000);
		
		printTest(test);
	}
	fprintf(stderr, "Finished generating all tests!\n");
	system("pause");
	return 0;
}
