/*
ID: espr1t
LANG: C++
TASK: Company Solver
COMP: Autumn National Contest, 2011
KEYWORDS: Graph, Tree, Recursion
*/

#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

#define MAX 1048576

void bubbleSort(std::vector<int>& v)
{
	int updated = 1;
	while (updated)
	{
		updated = 0;
		for (int i = 1; i < (int)v.size(); i++) if (v[i - 1] > v[i])
		{
			updated = 1;
			std::swap(v[i - 1], v[i]);
		}
	}
}

int main(void)
{
	int numTests = 20;
	for (int test = 0; test <= numTests; test++)
	{
		unsigned sTime = clock();
		fprintf(stderr, "Currently solving testcase %d...\n", test);
		char inpFile[32], solFile[32];
		sprintf(inpFile, "Company.%02d.in", test);
		sprintf(solFile, "Company.%02d.sol", test);
		FILE* in = fopen(inpFile, "rt");
		FILE* sol = fopen(solFile, "rt");
		
		int numNodes;
		static std::vector <int> v[MAX];
		for (int i = 0; i < MAX; i++) v[i].clear();
	
		fscanf(in, "%d", &numNodes);
		for (int node = 2; node <= numNodes; node++)
		{
			int from, to;
			fscanf(in, "%d %d", &from, &to);
			v[from].push_back(to);
		}
		for (int i = 1; i <= numNodes; i++)
			bubbleSort(v[i]);
		for (int i = 1; i <= numNodes; i++)
			std::reverse(v[i].begin(), v[i].end());
		
		static int ans[MAX], ansSize;
		static int index[MAX];
		static int stack[MAX], stackSize;
		
		ansSize = 0;
		stackSize = 0;
		memset(index, 0, sizeof(index));
		stack[stackSize++] = 1;
		while (stackSize)
		{
			int node = stack[stackSize - 1];
			if (index[node] < (int)v[node].size())
				stack[stackSize++] = v[node][index[node]++];
			else ans[ansSize++] = stack[--stackSize];
		}
		for (int i = ansSize - 1; i >= 0; i--)
		{
			int cur;
			fscanf(sol, "%d", &cur);
			if (ans[i] != cur)
			{
				fprintf(stderr, "  ++ this test is different.\n");
				break;
			}
		}
		fclose(in); fclose(sol);
		fprintf(stderr, "  >> execution time: %.3lfs\n", (double)(clock() - sTime) / CLOCKS_PER_SEC);
	}
	fprintf(stderr, "Finished solving all tests!\n");
	system("pause");
	return 0;
}
