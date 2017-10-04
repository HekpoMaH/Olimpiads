#include <iostream>
#include <cstdio>
using namespace std;

const int MAXM = 1000;
const int MAXN = 30;

int M, N;

bool data[MAXM][MAXN][MAXN];

bool ok[MAXM];

bool temp[MAXN][MAXN];
bool arr[MAXN][MAXN];

bool eq(bool A[][MAXN], bool B[][MAXN])
{
 for (int i = 0; i < N; i++)
  for (int j = 0; j < N; j++)
   if (A[i][j] != B[i][j]) return false;
 return true;
}

void rotate90(bool A1[][MAXN])
{
 int k = 0, l = 0;
 for (int i = 0; i < N; i++)
 {
  l = 0;
  for (int j = N - 1; j >= 0; j--)
  {
   temp[k][l] = A1[j][i];
   l++;
  }
  k++;
 }
 
 memcpy(A1, temp, 900);
}

bool equal(bool A1[][MAXN], bool A2[][MAXN])
{
 memcpy(arr, A1, 900);
 
 if (eq(A1, A2)) return true;
 rotate90(A1);
 if (eq(A1, A2)) return true;
 rotate90(A1);
 if (eq(A1, A2)) return true;
 rotate90(A1);
 if (eq(A1, A2)) return true;
 
 int k = 0, l = 0;
 
 for (int i = 0; i < N; i++)
 {
  l = 0;
  for (int j = N - 1; j >= 0; j--)
  {
   temp[k][l] = arr[i][j];
   l++;
  }
  k++;
 }
 
 memcpy(arr, temp, 900);
 
 if (eq(arr, A2)) return true;
 rotate90(arr);
 if (eq(arr, A2)) return true;
 rotate90(arr);
 if (eq(arr, A2)) return true;
 rotate90(arr);
 if (eq(arr, A2)) return true;
 
 return false;
}

int main()
{
 scanf("%d %d", &M, &N);
 
 for (int k = 0; k < M; k++)
 {
  for (int i = 0; i < N; i++)
  {
   char s[N + 2]; scanf("%s", s);
   for (int j = 0; j < N; j++)
    data[k][i][j] = s[j] - '0';
  }
 }
 
 memset(ok, true, sizeof(ok));
 
 for (int i = 0; i < M; i++)
 {
  if (!ok[i]) continue;
  for (int j = i + 1; j < M; j++)
   if (ok[j] && equal(data[i], data[j])) ok[j] = false;
 }
 
 int ans = 0;
 
 for (int i = 0; i < M; i++) ans += ok[i];
 
 printf("%d\n", ans);
 
 return 0;
}
