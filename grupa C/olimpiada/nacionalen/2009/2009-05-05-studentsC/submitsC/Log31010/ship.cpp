/*
TASK: ship
LANG: C++
*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n;
struct node {
	int weight;
	int final_pos;
};
node final[10000];
vector<int> v;
int ind[10000];
inline bool sravni(int a, int b) {
	if (final[a].weight < final[b].weight) {
		return 0;
	}
	return 1;
}
int main() {
	scanf("%d", &n);
	for (int i = 0;i < n; ++i) {
		scanf("%d", &final[i].weight);
		ind[i] = i;
	}
	for (int i = 0;i < n; ++i) {
		scanf("%d", &final[i].final_pos);
	}
	sort(ind, ind + n, sravni);
	//for (int i = 0;i < n; ++i) printf(" %d %d\n", ind[i], final[ind[i]].weight);
	//puts("");
	node cur;
	int ans = 0;
	int swap_vector;
	node swap_final;
	for (int i = 0;i < n; ++i) {
		if (final[ind[i]].final_pos != ind[i]) {
			v.clear();
			v.push_back(ind[i]);
			cur = final[ind[i]];
			while (cur.weight >= final[cur.final_pos].weight) {
				v.push_back(cur.final_pos);
				cur = final[cur.final_pos];
			}
			for (unsigned j = v.size() - 1;j > 0; --j) {
				ans += final[v[j]].weight + final[v[j - 1]].weight;
				//printf("%d\n", v[j]);
				//printf("%d %d\n", final[v[j]].weight, final[v[j - 1]].weight);
				swap_final = final[v[j]];
				final[v[j]] = final[v[j - 1]];
				final[v[j - 1]] = swap_final;
				//swap_vector = v[j];
				//v[j] = v[j - 1];
				//v[j - 1] = swap_vector;
			}
			//puts("");
		}
	}
	for (int i = 0;i < n; ++i) {
		//printf("%d %d\n", final[i].weight, final[i].final_pos);
	}
	printf("%d\n", ans);
	return 0;
}
