/*
ID: espr1t
LANG: C++
TASK: Frog
COMP: NOI Round 3, 2011
KEYWORDS: Dynamic Programming, RMQ
*/

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <sstream>

#define MAX 131072
#define TREE 262144
#define INF 1111111111

using namespace std;

int n;
int a[MAX][3];
int tree[5][TREE][2];
long long dyn[MAX];

void update(int type, int pos, int val)
{
	val += (type + 1) * (n - pos);
	int idx = pos + (TREE >> 1);
	while (idx)
	{
		if (tree[type][idx][0] < val)
		{
			tree[type][idx][0] = val;
			tree[type][idx][1] = pos;
		}
		idx >>= 1;
	}
}

int query(int type, int idx)
{
	idx += (TREE >> 1);
	int ret = tree[type][idx][0];
	int pos = tree[type][idx][1];
	int isRight = (idx & 1); idx >>= 1;
	
	while (idx)
	{
		if (isRight && ret < tree[type][idx << 1][0])
		{
			ret = tree[type][idx << 1][0];
			pos = tree[type][idx << 1][1];
		}
		isRight = (idx & 1); idx >>= 1;
	}
	return ret;
}

long long eval1()
{
	for (int i = 0; i < TREE; i++)
		for (int type = 0; type < 5; type++)
			tree[type][i][0] = -INF, tree[type][i][1] = 0;

	int ans = a[n - 1][0];
	for (int type = 0; type < 5; type++)
		update(type, n - 1, ans);
	
	for (int idx = n - 2; idx >= 0; idx--)
	{
		int right = idx + a[idx][2];
		if (right >= n) right = n - 1;
		ans = a[idx][0] + query(a[idx][1] - 1, right)- (n - idx) * a[idx][1];
		for (int type = 0; type < 5; type++)
			update(type, idx, ans);
	}
	return ans;
}

long long eval2()
{
	int longest = -1;
	dyn[n - 1] = a[n - 1][0];
	for (int i = n - 2; i >= 0; i--)
	{
		dyn[i] = a[i][0] + dyn[i + 1] - a[i][1];
		for (int c = 2; c <= min(10000, a[i][2]); c++)
		{
			if (i + c >= n) break;
			if (dyn[i] < a[i][0] + dyn[i + c] - c * a[i][1])
				longest = max(longest, c);
			dyn[i] = max(dyn[i], a[i][0] + dyn[i + c] - c * a[i][1]);
		}
	}
	fprintf(stderr, "  -- longest is: %d\n", longest);
	return dyn[0];
}

string toString(long long num)
{
	char buff[32];
	stringstream ss;
	ss << num;
	ss >> buff;
	return buff;
}

int main(void)
{
	int numTests = 20;
	for (int test = 0; test <= numTests; test++)
	{
		fprintf(stderr, "Solving testcase %d...\n", test);
		unsigned sTime = clock();

		char inpFile[32], outFile[32];
		sprintf(inpFile, "Frog.%02d.in", test);
		sprintf(outFile, "Frog.%02d.sol", test);
		
		FILE *in = fopen(inpFile, "rt");
		FILE *out = fopen(outFile, "wt");
		
		fscanf(in, "%d", &n);
		for (int i = 0; i < n; i++)
			fscanf(in, "%d %d %d", &a[i][0], &a[i][1], &a[i][2]);

		long long ans1 = eval1();
		long long ans2 = eval2();
		if (ans1 != ans2)
		{
			fprintf(stderr, "\nSolution1 says answer is %s where solution2 says it is %s!\n", toString(ans1).c_str(), toString(ans2).c_str());
			system("pause");
		}
		fprintf(out, "%s\n", toString(ans1).c_str());
		fclose(in); fclose(out);
		fprintf(stderr, "  -- execution time: %.3lfs\n", (double)(clock() - sTime) / (double)CLOCKS_PER_SEC);
	}
	fprintf(stderr, "Finished solving all tests!\n");
	system("pause");
	return 0;
}
