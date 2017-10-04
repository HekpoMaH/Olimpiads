/*
ID: espr1t
LANG: C++
TASK: Frog
COMP: NOI Round 3, 2011
KEYWORDS: Dynamic Programming, RMQ
*/

#include <cstdio>

#define MAX 131072
#define TREE 262144
#define INF 1111111111

FILE *in; FILE *out;

int n;
int a[MAX][3];
int tree[5][TREE][2];

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

int eval()
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
		ans = a[idx][0] + query(a[idx][1] - 1, right) - (n - idx) * a[idx][1];
		for (int type = 0; type < 5; type++)
			update(type, idx, ans);
	}
	return ans;
}

int main(void)
{
	in = stdin; out = stdout;
//	in = fopen("Frog.in", "rt"); out = fopen("Frog.out", "wt");
	
	fscanf(in, "%d", &n);
	for (int i = 0; i < n; i++)
		fscanf(in, "%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
	
	fprintf(out, "%d\n", eval());
	return 0;
}
