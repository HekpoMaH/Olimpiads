#include <cstdio>
int n;
int m;
int r;
int k;
int x;
int y;
int abs(int number) {
	if (number < 0) return -number;
	return number;
}
int main() {
	scanf("%d %d %d %d", &n, &m, &r, &k);
	r--;
	x = r / m;
	y = r % m;
	int x1, y1;
	int rast;
	int answer = 0;
	for (int i = 0;i < n * m; ++i) {
		x1 = i / m;
		y1 = i % m;
		rast = abs(x - x1) + abs(y - y1);
		if (rast == k) {
			answer += i + 1;
		} else if (rast < k) {
			if ((k - rast) % 2 == 0) {
				answer += i + 1;
			}
		}
	}
	printf("%d\n", answer);
	return 0;
}
