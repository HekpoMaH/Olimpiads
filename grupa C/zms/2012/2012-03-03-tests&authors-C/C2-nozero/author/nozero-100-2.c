#include <stdio.h>

#define MAXN 1000000

int a[MAXN], stack[MAXN], n, m;
long long sum;

int main () {
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	m = 0;
	sum = 0;
	for (i = 0; i < n; i++) {
		if (a[i] == 0) {
			if (m == 0) {
				sum = -1;
				break;
			} else {
				sum += (long long) (i - stack[--m]);
			}
		} else {
			stack[m++] = i;
		}
	}
	
	printf("%lld\n", sum);
	
	return 0;
}