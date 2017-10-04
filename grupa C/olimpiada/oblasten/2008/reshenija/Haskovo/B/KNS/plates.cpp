#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int m, n, br;
string A[1024][32];

bool check(int M, int N)
{
     int i, j;
     
     for (i=0; i<n; ++i)
     if (A[M][i] == A[N][i]) {}
     else break;
     if (i == n) return false;
     
     for (i=0; i<n; ++i)
         for (j=0; j<n; ++j)
          if (A[M][i][j] == A[N][j][i]) {}
          else goto q1;
     q1:
     if (i == n) return false;
     
     for (i=0; i<n; ++i)
         for (j=0; j<n; ++j)
          if (A[M][i][j] == A[N][n-1-i][n-1-j]) {}
          else goto q2;
     q2:
     if (i == n) return false;
     
     for (i=0; i<n; ++i)
         for (j=0; j<n; ++j)
          if (A[M][i][j] == A[N][j][n-1-i]) {}
          else goto q3;
     q3:
     if (i == n) return false;
     
     for (i=0; i<n; ++i)
         for (j=0; j<n; ++j)
         if (A[M][i][j] == A[N][n-1-j][i]) {}
         else goto q4;
     q4:
     if (i == n) return false;
     
     for (i=0; i<n; ++i)
         for (j=0; j<n; ++j)
         if (A[M][i][j] == A[N][i][n-1-j]) {}
         else goto q5;
     q5:
     if (i == n) return false;
     
     for (i=0; i<n; ++i)
         for (j=0; j<n; ++j)
          if (A[M][i][j] == A[N][n-1-j][n-1-i]) {}
          else goto q6;
     q6:
     if (i == n) return false;
     
     for (i=0; i<n; ++i)
     if (A[M][i] == A[N][n-1-i]) {}
     else break;
     if (i == n) return false;
     
     return true;
     
}

void solve()
{
     for (int i=0; i<m-1; ++i)
         for (int j=i+1; j<m; ++j)
         if (check(i, j)) ++br;
     printf("%d\n", br);
}

void read()
{
     scanf("%d%d", &m , &n);
     for (int i=0; i<m; ++i)
         for (int j=0; j<n; ++j)
             cin >> A[i][j];
}

int main()
{
    read();
    solve();
return 0;
}
