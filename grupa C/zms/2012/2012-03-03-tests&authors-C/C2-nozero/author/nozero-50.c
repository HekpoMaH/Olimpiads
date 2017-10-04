#include <stdio.h>

#define MAXN 1000000

int a[MAXN];
int n;
long long sum;

int readInput() {
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
}

void solve() {
	int i, j, flag;
	
	sum = 0;
	for (i = 0; i < n; i++) {
		if (a[i] == 0) {
			flag = 1;
			for (j = i - 1; j >= 0; j--) {
				if (a[j] == 2) {
					flag = 0;
					a[j] = 0;
					sum += (i - j);
					break;
				}
			}
			if (flag == 1) {
				sum = -1;
				break;
			}
		}
	}
}

void writeOutput() {
	printf("%lld\n", sum);
}

int main () {
	readInput();
	solve();
	writeOutput();
	return 0;
}