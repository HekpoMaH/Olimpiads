#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int M;
int answer[1 << 20];
int barrels[128];
void calcDP(int s) {
	for (int i = 1;i <= s; ++i) answer[i] = s;
	for (int wine = 0;wine < s; ++wine) {
		for (int barrel = 0;barrel < n; ++barrel) {
			if (wine + barrels[barrel] <= s) {
				if (answer[wine + barrels[barrel]] > answer[wine] + 1) {
					answer[wine + barrels[barrel]] = answer[wine] + 1;
				}
			}
		}
	}
}
bool should_break;
int calcMin(int barrel, int left, int prev_count) {
	int k = left / barrels[barrel];
	if (prev_count * barrels[barrel + 1] < k * barrels[barrel]) 
	{
		should_break = true;
		return M;
	}
	if (left % barrels[barrel] == 0) return k;
	if (barrel == 0) return left;
	if (barrel == 1) return (left / barrels[0]) + (left % barrels[0]);
		int min = left;
	int current;
	bool should_break_old = should_break;
	should_break = false;
	while (k >= 0 && !should_break)
	{
		if (left - (k * barrels[barrel]) <= 1000000)
		{
			current = answer[left - (k * barrels[barrel])] + k;
		}
		else
		{
			current = calcMin(barrel - 1, left - (k * barrels[barrel]), k) + k;
			//printf("%d %d\n", k, barrels[barrel]);
		}
		if (min > current) min = current;
//		if (left / 2 > (k * barrels[barrel])) should_break = true;
		k--;
	}
	should_break = should_break_old;
	return min;
}
int main() {
	int s;
	scanf("%d %d", &s, &n);
	M = s;
	for (int i = 0;i < n; ++i) {
		scanf("%d", &barrels[i]);
	}
	sort(barrels, barrels + n);
	while (barrels[n - 1] > s) n--;
	if (s <= 1000000) {
		calcDP(s);
		printf("%d\n", answer[s]);
	} else {
		calcDP(1000000);
		barrels[n] = M;
		printf("%d\n", calcMin(n - 1, s, 2));
	}
	return 0;
}
