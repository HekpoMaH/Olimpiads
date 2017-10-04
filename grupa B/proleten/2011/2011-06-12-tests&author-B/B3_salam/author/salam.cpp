//Task: salam
//Author: Momchil Ivanov

#include <stdio.h>

#define MAXN 1000000

int n;
int a[MAXN];
int best_to[MAXN], best_to_left[MAXN];
int best, best_left, best_right;

void readInput() {
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
}

void solve() {
	int i, sum;

	if (a[0] >= 0) {
		best_to[0] = a[0];
		best_to_left[0] = 0;
	} else {
		best_to[0] = 0;
		best_to_left[0] = -1;

	}

	sum = a[0];
	for (i = 1; i < n; i++) {
		sum += a[i];
		if (sum >= best_to[i-1]) {
			best_to[i] = sum;
			best_to_left[i] = i;
		} else {
			best_to[i] = best_to[i-1];
			best_to_left[i] = best_to_left[i-1];
		}
	}

	best = 0;
	best_left = -1;
	best_right = n;

	if (best_to[n-1] > best) {
		best = best_to[n-1];
		best_left = best_to_left[n-1];
	}

	sum = 0;
	for (i = n-1; i > 0; i--) {
		sum += a[i];
		if ((sum + best_to[i-1] > best) || ((sum + best_to[i-1] == best) && (best_to_left[i-1] >= best_left))) {
			best = sum + best_to[i-1];
			best_left = best_to_left[i-1];
			best_right = i;
		}
	}
}

void writeOutput() {
	printf("%d\n", best);
	printf("%d %d\n", best_left+1, best_right+1);
}

int main() {
	readInput();
	solve();
	writeOutput();

	return 0;
}


