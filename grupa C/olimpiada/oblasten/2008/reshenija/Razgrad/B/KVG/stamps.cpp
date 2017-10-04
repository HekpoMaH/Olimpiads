/*
stamps.cpp
Solution by Dynamic Programming, O(M*N)
GREEDY DOESN"T WORK - 1 7 8 -> 21 min 3 7-cent stamps
*/
#include <stdio.h>
#include <stdlib.h>

#define MAXN 3050
#define MAXM 5050

int a[MAXN], dp[MAXM];

int main(){
	int i, j, s, n, min;
	scanf("%d %d", &s, &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	/*
	Solution with dynamic programming - 
	dp[i] = min(dp[i - a[j]])
	*/
	dp[0] = 0;	//initial
	for(i = 1; i <= s; i++){
		min = i;	//when using only 1's
		for(j = 0; j < n; j++){
			if(i - a[j] >= 0 && dp[i - a[j]] + 1 < min)
				min = dp[i - a[j]] + 1;
		}
		dp[i] = min;
	}
	printf("%d\n", dp[s]);

	return 0;
}