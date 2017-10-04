/*
LANG: C++
TASK: RIDDLES
AUTHOR: Ivan Vladimirov Ivanov
*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX 100005

void input(void);
void solve(void);

int try_it(int len);

int n, m;
int A[MAX];
int B[MAX];

int main(void)
{
  int t;
  scanf("%d", &t);
  while(t--) {
    input();
    solve();
  }
    
  return 0;
}

void input(void)
{
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++) scanf("%d", &A[i]);
}

void solve(void)
{
  int left  = 0;
  int right = n + 1;
  int res   = n + 1;
  while(left <= right) {
    int mid = (left + right) / 2;
    if(try_it(mid)) { 
      res = mid;
      right = mid - 1;
    }
    else {
      left = mid + 1;
    }
  }
  
  printf("%d\n", (res == n + 1) ? -1 : res);
}

int try_it(int len)
{
  for(int i = 0; i < len; i++) B[i] = A[i];
  
  sort(B, B + len);
  
  int sum = 0;
  for(int i = 0; i < len; i++) {
    if(B[i] > sum + 1) break;
    sum += B[i];
    if(sum >= m) break;
  } 
    
  return (sum >= m) ? 1 : 0;
}

