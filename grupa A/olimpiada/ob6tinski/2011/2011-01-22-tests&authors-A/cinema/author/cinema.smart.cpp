/*
TASK: cinema
LANG: C++
AUTHOR: Alexander 'espr1t' Georgiev
CONTEST: National Olympiad in Informatics, Round 1 
*/

#include <cstdio>
#define MAX 128

int n, m, r, c;
char ma3x[MAX][MAX];
int sums[MAX][MAX];

int main(void)
{
	FILE *in = stdin; FILE *out = stdout;
//	in = fopen("cinema.in", "rt"); out = fopen("cinema.out", "wt");
	
	fscanf(in, "%d %d", &n, &m);
	fscanf(in, "%d %d", &r, &c);
	for (int row = 0; row < n; row++)
		fscanf(in, "%s", ma3x[row]);
	
	int ans = 0, cnt;
	for (int row = 1; row <= n; row++)
	{
		for (int col = 1; col <= m; col++)
		{
			sums[row][col] = (ma3x[row - 1][col - 1] == '#');
			sums[row][col] += sums[row - 1][col];
			sums[row][col] += sums[row][col - 1];
			sums[row][col] -= sums[row - 1][col - 1];
			
			if (row >= r && col >= c)
			{
				cnt = sums[row][col];
				cnt -= sums[row - r][col];
				cnt -= sums[row][col - c];
				cnt += sums[row - r][col - c];
				ans += !cnt;
			}
		}
	}
	fprintf(out, "%d\n", ans);	
	return 0;
}
