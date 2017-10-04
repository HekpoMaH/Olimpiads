/*
ID: espr1t
LANG: C++
TASK: Frog
COMP: NOI Round 3, 2011
KEYWORDS: Dynamic Programming
*/

#include <cstdio>
#include <sstream>
#include <algorithm>

#define MAX 131072

using namespace std;
FILE *in; FILE *out;

int n;
int a[MAX][3];
long long dyn[MAX];

int main(void)
{
	in = stdin; out = stdout;
//	in = fopen("Frog.in", "rt"); out = fopen("Frog.out", "wt");
	
	fscanf(in, "%d", &n);
	for (int i = 0; i < n; i++)
		fscanf(in, "%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
	
	dyn[n - 1] = a[n - 1][0];
	for (int i = n - 2; i >= 0; i--)
	{
		dyn[i] = a[i][0] + dyn[i + 1] - a[i][1];
		for (int c = 2; c <= a[i][2]; c++)
		{
			if (i + c >= n) break;
			dyn[i] = max(dyn[i], a[i][0] + dyn[i + c] - c * a[i][1]);
		}
	}
	stringstream ss;
	ss << dyn[0];
	char buff[32];
	ss >> buff;
	fprintf(out, "%s\n", buff);
	
	return 0;
}
