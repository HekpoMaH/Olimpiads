/*
LANG: C++
TASK: Triples
ID: espr1t
TOUR: Dean's Cup 2009
*/

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>

#define MAX 1024
#define INF 0xDEAD

using namespace std;
FILE *in; FILE *out;

int n;
char vis[MAX][MAX];
long long a[MAX];
long long dyn[MAX][MAX];

long long recurse(int left, int right)
{
	long long ans = -INF;
	if (left > right) return 0;
	if (vis[left][right]) return dyn[left][right];

	// Take leftmost
	ans = max(ans, recurse(left + 1, right) + a[left]);
	// Take rightmost
	ans = max(ans, recurse(left, right - 1) + a[right]);

	if (right - left >= 1)
	{
		// Take leftmost two
		ans = max(ans, recurse(left + 2, right) + a[left] * a[left + 1]);
		// Take leftmost and rightmost
		ans = max(ans, recurse(left + 1, right - 1) + a[left] * a[right]);
		// Take rightmost two
		ans = max(ans, recurse(left, right - 2) + a[right] * a[right - 1]);
	}
	if (right - left >= 2)
	{
		// Take leftmost three
		ans = max(ans, recurse(left + 3, right) + a[left] * a[left + 1] * a[left + 2]);
		// Take leftmost two and rightmost one
		ans = max(ans, recurse(left + 2, right - 1) + a[left] * a[left + 1] * a[right]);
		// Take leftmost one and rightmost two
		ans = max(ans, recurse(left + 1, right - 2) + a[left] * a[right - 1] * a[right]);
		// Take rightmost three
		ans = max(ans, recurse(left, right - 3) + a[right] * a[right - 1] * a[right - 2]);
	}

	vis[left][right] = 1;
	return dyn[left][right] = ans;
}

int main(void)
{
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	sort(a, a + n);

	memset(vis, 0, sizeof(vis));
	cout << recurse(0, n - 1) << endl;
	return 0;
}
