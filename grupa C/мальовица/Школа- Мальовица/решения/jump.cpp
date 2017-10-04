
#include <vector>
#include <limits>
#include <iostream>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> get(n + 2, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> get[i];
	}
	vector<int> best_sum(n + 2, numeric_limits<int>::min() / 2);
	vector<int> best_p(n + 2, -1);
	best_sum[0] = 0;
	best_p[0] = 0;
	for (int i = 1; i <= n + 1; ++i) {
		for (int j = 1; j <= k && j <= i; ++j) {
		    if (best_sum[i - j] + get[i] > best_sum[i]) {
                best_sum[i] = best_sum[i - j] + get[i];
                best_p[i] = max(best_p[i - j], j);
            } else if (best_sum[i - j] + get[i] == best_sum[i] && max(best_p[i - j], j) < best_p[i]) {
                best_sum[i] = best_sum[i - j] + get[i];
                best_p[i] = max(best_p[i - j], j);
            }
		}
	}
	cout << best_sum[n + 1] << " " << best_p[n + 1] << "\n";
	return 0;
}
