#include<iostream>
# include <cstdio>

using namespace std;

const int MAX_N = 2010;

int n, m, k;

int ans = -1e9;

int a[MAX_N][MAX_N];
int max_up[MAX_N][MAX_N];
int max_down[MAX_N][MAX_N];
int max_left[MAX_N][MAX_N];
int max_right[MAX_N][MAX_N];
int max_rubka[MAX_N][MAX_N];

int alpha[32];
char c[MAX_N];

inline int max (int aa, int bb)
{
	return (aa > bb) ? aa : bb;
}

int main ()
{
	int i, j;
	scanf ("%d", &k);
	for (i = 0; i < k; i ++)
		scanf ("%d", &alpha[i]);
	scanf ("%d%d", &n, &m);
	
	for (i = 1; i <= n; i ++)
	{
		scanf ("%s", c);
		for (j = 1; j <= m; j ++)
			a[i][j] = alpha[c[j - 1] - 'a']; 
	}
	
	for (i = 1; i <= n; i ++)
	{
		for (j = 1; j <= m; j ++)
			max_left[i][j] = max (max_left[i][j - 1] + a[i][j - 1], 0);
		for (j = m; j >= 1; j --)
			max_right[i][j] = max (max_right[i][j + 1] + a[i][j + 1], 0);
	}
	
	for (i = 1; i <= m; i ++)
	{
		for (j = 1; j <= n; j ++)
			max_up[j][i] = max (max_up[j - 1][i] + a[j - 1][i], 0);
		for (j = n; j >= 1; j --)
			max_down[j][i] = max (max_down[j + 1][i] + a[j + 1][i], 0);
	}
	
	for (i = 1; i <= n; i ++)
		for (j = 1; j <= m; j ++)
			max_rubka[i][j] = max (max_rubka[i][j - 1] + a[i][j - 1], max_left[i][j - 1] + max_up[i][j - 1] + a[i][j - 1]);
			
   for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
         cout<<max_left[i][j]<<" ";
      }
      cout<<"\n";
   }
	for (i = 1; i <= n; i ++)
		for (j = 2; j <= m; j ++)
		{
			/**
			printf ("%d %d %d\n", i, j, a[i][j]);
			printf ("left -> %d\n", max_rubka[i][j]);
			printf ("right -> %d\n", max_right[i][j]);
			printf ("down -> %d\n", max_down[i][j]);
			printf ("up -> %d\n", max_up[i][j]);
			printf ("all -> %d\n", a[i][j] + max_right[i][j] + max_up[i][j] + max_down[i][j] + max_rubka[i][j]);
			**/
			ans = max (ans, a[i][j] + max_right[i][j] + max_up[i][j] + max_down[i][j] + max_rubka[i][j]);
		}
	printf ("%d\n", ans);
	return 0;
}
