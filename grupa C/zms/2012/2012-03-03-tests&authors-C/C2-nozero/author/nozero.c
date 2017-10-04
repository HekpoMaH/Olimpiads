#include <stdio.h>

#define MAXN 1000000

int map[MAXN];
int n;
long long sum, deficit;

void readInput() {
	int i;
	
    scanf("%d", &n);
	getchar();
    for (i = 0; i < n; i++) {
		scanf("%d", &map[i]);
	}
}

void solve() {
	int i;
	
	sum = 0;
	
	if (map[n-1] == 0)
		deficit = 1;
	else
		deficit = 0;

	for (i = n-2; i >= 0; i--) {
		sum += deficit;
		if (map[i] == 0) {
			deficit++;
		} else {
			if (deficit > 0)
				deficit--;
		}
	}
}

void writeOutput() {
	printf("%lld\n", deficit == 0 ? sum : -1);
}

int main () {

	readInput();
	solve();
	writeOutput();
	
    return 0;
}
