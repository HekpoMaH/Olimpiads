/*
TASK: Roads
Author: Alexander Georgiev
*/

#include <cstdio>
#include <cstring>

#define MAX 128
#define MOD 1000000009
FILE* in; FILE* out;

int n, m;
char a[MAX][MAX];

int dist[MAX][MAX], dyn[MAX][MAX];
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

int recurse(int row, int col)
{
	if (dist[row][col] == 0) return 1;
	if (dyn[row][col] != -1) return dyn[row][col];
	
	int ans = 0;
	for (int i = 0; i < 4; i++)
	{
		int nrow = row + dir[i][0]; if (nrow < 0 || nrow >= n) continue;
		int ncol = col + dir[i][1]; if (ncol < 0 || ncol >= m) continue;
		if (dist[nrow][ncol] < dist[row][col])
			ans = (recurse(nrow, ncol) + ans) % MOD;
	}
	return dyn[row][col] = ans;
}

int main(void)
{
	in = stdin; out = stdout;
//	in = fopen("Roads.in", "rt"); out = fopen("Roads.out", "wt");
	
	fscanf(in, "%d %d", &n, &m);
	for (int i = 0; i < n; i++) fscanf(in, "%s", a[i]);

	int srow, scol, erow, ecol;
	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < m; col++)
		{
			if (a[row][col] == 'E') srow = row, scol = col;
			if (a[row][col] == 'X') erow = row, ecol = col;
		}
	}
	
	memset(dist, 11, sizeof(dist));
	dist[erow][ecol] = 0;

	static int q[MAX * MAX][2], qlen = 0;
	q[qlen][0] = erow; q[qlen][1] = ecol; qlen++;
	for (int qidx = 0; qidx < qlen; qidx++)
	{
		int row = q[qidx][0], col = q[qidx][1];
		for (int i = 0; i < 4; i++)
		{
			int nrow = row + dir[i][0]; if (nrow < 0 || nrow >= n) continue;
			int ncol = col + dir[i][1]; if (ncol < 0 || ncol >= m) continue;
			if (a[nrow][ncol] == '#') continue;
			if (dist[nrow][ncol] > dist[row][col] + 1)
			{
				dist[nrow][ncol] = dist[row][col] + 1;
				q[qlen][0] = nrow; q[qlen][1] = ncol; qlen++;
			}
		}
	}
	
	if (dist[srow][scol] > n * m) fprintf(out, "0\n");
	else
	{
		memset(dyn, -1, sizeof(dyn));
		fprintf(out, "%d\n", recurse(srow, scol));
	}

	return 0;
}
