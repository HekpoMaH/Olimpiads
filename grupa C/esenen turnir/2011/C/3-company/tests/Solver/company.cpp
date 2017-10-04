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

int main(void)
{
	int numTests = 20;
	for (int test = 0; test <= numTests; test++)
	{
		unsigned sTime = clock();
		fprintf(stderr, "Currently solving testcase %d...\n", test);
		char inpFile[32], outFile[32];
		sprintf(inpFile, "Company.%02d.in", test);
		sprintf(outFile, "Company.%02d.sol", test);
		FILE* in = fopen(inpFile, "rt");
		FILE* out = fopen(outFile, "wt");
		
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
			std::sort(v[i].rbegin(), v[i].rend());
		
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
			fprintf(out, "%d%c", ans[i], i == 0 ? '\n' : ' ');
		fclose(in); fclose(out);
		fprintf(stderr, "  >> execution time: %.3lfs\n", (double)(clock() - sTime) / CLOCKS_PER_SEC);
	}
	fprintf(stderr, "Finished solving all tests!\n");
	system("pause");
	return 0;
}
