/*
ID: espr1t
LANG: C++
TASK: Company
COMP: Autumn National Contest, 2011
KEYWORDS: Graph, Tree, Recursion
*/

#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX 1048576

int main(void)
{
	FILE* in = stdin; FILE* out = stdout;
//	in = fopen("Company.in", "rt"); out = fopen("Company.out", "wt");
	
	int numNodes;
	static std::vector <int> v[MAX];

	fscanf(in, "%d", &numNodes);
	for (int edge = 0; edge < numNodes - 1; edge++)
	{
		int from, to;
		fscanf(in, "%d %d", &from, &to);
		v[from].push_back(to);
	}
	for (int i = 1; i <= numNodes; i++)
		std::sort(v[i].rbegin(), v[i].rend());
	
	static int ans[MAX], ansSize = 0;
	static int index[MAX] = {0};
	static int stack[MAX], stackSize = 0;
	
	stack[stackSize++] = 1;
	while (stackSize)
	{
		int node = stack[stackSize - 1];
		if (index[node] < (int)v[node].size())
			stack[stackSize++] = v[node][index[node]++];
		else ans[ansSize++] = stack[--stackSize];
	}
	for (int i = ansSize - 1; i >= 0; i--)
		fprintf(out, "%d%c", ans[i], i == 0 ? '\n' : ' ');
	
	return 0;
}
