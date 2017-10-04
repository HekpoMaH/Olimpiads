#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 256, mod = 1e6 + 7;
int n, m, k;
char c[MAXN][MAXN];
long long M[MAXN][MAXN], S, E;
int x[4] = {0, 0, 1, -1}, y[4] = {1, -1, 0, 0};
void read()
{
	scanf("%d%d%d", &n, &m, &k);
	int i;
	for(i = 0; i < n; ++i)
	    scanf("%s", &c[i]);
}
inline int num(int i, int j)
{
	return i * m + j + 1;
}
bool is_in(int i, int j)
{
	return (i >= 0) && (j >= 0) && (i < n) && ( j < m);
}
long long ans = 0;
void init()
{
	int i, j;
	for(i = 0; i < n; ++i)
		for(j = 0; j < m; ++j)
		{
			if(c[i][j] == 'X')
				continue;
			if(c[i][j] == 'F')
			{
				E = num(i, j);
				continue;
			}
			if(c[i][j] == 'D')
				S = num(i, j);
			int t;
			for(t = 0; t < 4; t++)
			{
				int i1 = i + x[t];
				int j1 = j + y[t];
				if(is_in(i1, j1) && c[i1][j1] != 'D' && c[i1][j1] != 'X') 
				{
					M[num(i, j)][num(i1, j1)] = 1;	
				}
			}
		}
}
long long tmp[MAXN][MAXN], N;
void mult(long long a[MAXN][MAXN], long long b[MAXN][MAXN], bool p)
{
	int i, j, kk;
	long long t[MAXN][MAXN];
	memset(t, 0, sizeof(t));
	for(i = 1; i <= N; ++i)
		for(j = 1; j <= N; ++j)
			for(kk = 1; kk <= N; ++kk)
			{
				t[i][j] = (t[i][j] + a[i][kk] * b[kk][j]);
					t[i][j] %= mod;
			}
	if(p == 0)
		memcpy(tmp, t, sizeof(t));
	else
		memcpy(M, t, sizeof(t));
}
void solve()
{
	int i;
	N = m * n;
	if(k)
	ans += M[S][E];
	for(i = 3; i <= k; i *= 3)   
	{
		mult(M, M, 0);
		mult(tmp, M, 1);
		ans = (ans + M[S][E]) % mod;
                for(int i1=0;i1<N;i1++){
                   for(int j1=0;j1<N;j1++){
                      cout<<M[i1][j1]<<" ";
                   }
                   cout<<"\n";
                }
	}
	printf("%d\n", ans);
}
int main()
{
	read();
	init();
	solve();
	return 0;
}
