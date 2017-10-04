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

int main(void)
{
	FILE *in = stdin; FILE *out = stdout;
//	in = fopen("cinema.in", "rt"); out = fopen("cinema.out", "wt");
	
	fscanf(in, "%d %d", &n, &m);
	fscanf(in, "%d %d", &r, &c);
	for (int row = 0; row < n; row++)
		fscanf(in, "%s", ma3x[row]);
	
	int ans = 0;
	for (int row = 0; row + r <= n; row++)
	{
		for (int col = 0; col + c <= m; col++)
		{
			int flag = 1;
			for (int irow = 0; irow < r; irow++)
				for (int icol = 0; icol < c; icol++)
					if (ma3x[row + irow][col + icol] == '#') flag = 0;
			ans += flag;
		}
	}
	fprintf(out, "%d\n", ans);	
	return 0;
}
