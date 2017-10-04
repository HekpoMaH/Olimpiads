#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> events;
	vector<pair<int, int> > add;
	vector<pair<int, int> > remove;
	for (int i = 0; i < n; ++i) {
		int a, b, cost;
		scanf("%d %d %d", &a, &b, &cost);
		add.push_back(make_pair(a, cost));
		remove.push_back(make_pair(b, cost));
		events.push_back(a);
		events.push_back(b);
	}
	sort(add.begin(), add.end());
	sort(remove.begin(), remove.end());
	sort(events.begin(), events.end());
	events.resize(unique(events.begin(), events.end()) - events.begin());
	reverse(add.begin(), add.end());
	reverse(remove.begin(), remove.end());
	LL sum = 0;
	LL res = 0;
	LL perUnit = 0;
	for (int i = 0; i < int(events.size()); ++i) {
		if (i > 0)
			sum += perUnit * LL(events[i] - events[i - 1]);
		sum = max(sum, 0LL);
		res = max(res, sum);
		while (!remove.empty() && remove.back().first == events[i]) {
			perUnit -= remove.back().second;
			remove.pop_back();
		}
		while (!add.empty() && add.back().first == events[i]) {
			perUnit += add.back().second;
			add.pop_back();
		}
	}
	printf("%lld\n", res);
	return 0;
}
