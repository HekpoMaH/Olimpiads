/*
TASK: sheep
LANG: C++
AUTHOR: Alexander Georgiev
CONTEST: Winter Mathematical Festivals
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <stdio.h>

using namespace std;

#define MAX 1024

int n, k, a[MAX];

bool eval(int cap)
{
	int vis[MAX];
	memset(vis, 0, sizeof(vis));

	int ans = 0, taken = 0;
	while (taken < n)
	{
		ans++;
		if (ans > k) return false;
		int rem = cap;
		for (int i = 0; i < n; i++) if (!vis[i])
			if (rem >= a[i]) vis[i] = 1, rem -= a[i], taken++;
	}
	return true;
}

int main(void)
{

	int left = 0, right = 0;

    scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
	{
        scanf("%d", &a[i]);
		right += a[i];					// The weight of all sheep is an upper bound
		if (left < a[i]) left = a[i];	// The maximum weight is a lower bound
	}
	// Sort the weights in decreasing order (using bubble sort)
	for (int i = 0; i < n; i++)
		for (int c = 0; c < n - 1; c++)
			if (a[c] < a[c+1]) a[c] ^= a[c+1] ^= a[c] ^= a[c+1]; // Interesting swap() =)

	int ans = right;
	while (left <= right)				// Do a binary search over the answer
	{
		int mid = (left + right) / 2;
		if (eval(mid)) right = mid - 1, ans = mid;
		else left = mid + 1;
	}

	printf("%d\n", ans);
	return 0;
}
