/*
ID: espr1t
LANG: C++
TASK: Graze
KEYWORDS: Sorting, Binary Search, Greedy
*/

#include <cstdio>
#include <algorithm>

#define MAX 131072
#define INF 1000001
FILE* in; FILE* out;

int n, m, k;
int a[MAX], b[MAX];

bool eval(int len)
{
	int idx = 0, rem = k;
	for (int i = 0; i < n; i++)
	{
		if (rem <= 0)
			idx++, rem = k;
		while (idx < m && b[idx] < a[i] - len)
			idx++, rem = k;
		if (idx >= m) return false;
		if (a[i] < b[idx] - len) return false;
		rem--;
	}
	return true;
}

int main(void)
{
	in = stdin; out = stdout;
//	FILE* in = fopen("Graze.in", "rt"); out = fopen("Graze.out", "wt");
	
	fscanf(in, "%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++) fscanf(in, "%d", &a[i]);
	for (int i = 0; i < m; i++) fscanf(in, "%d", &b[i]);
	
	std::sort(a, a + n);
	std::sort(b, b + m);
	
	int left = 0, right = INF;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (eval(mid)) right = mid - 1;
		else left = mid + 1;
	}
	fprintf(out, "%d\n", right >= INF ? -1 : right + 1);
	return 0;
}
