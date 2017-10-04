/*
LANG: C++
TASK: FUEL
AUTHOR: Ivan Vladimirov Ivanov
*/
#include <cstdio>

using namespace std;

#define MAX 1048576
#define MOD 1000000007

int n;
int A[MAX];
int F[MAX];

int main(void)
{
	int n, target, len;
	scanf("%d %d %d", &n, &target, &len);
	A[0] = 0;
	for(int i = 1; i <= n; i++) scanf("%d", &A[i]);
	A[++n] = target;
	F[n] = 1;
	for(int i = n - 1; i >= 0; i--) {
	  int sum = 0;
	  for(int j = i + 1; j <= n && A[j] - A[i] <= len; j++) {
	    sum = (sum + F[j]) % MOD;
	  }
	  F[i] = sum;
	}
	printf("%d\n", F[0]);
    return 0;
}

