
#include <vector>
#include <cstdio>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

pair<bool, vector<int> > horner(vector<int> coef, int by) {
	int z = 0;
	vector<int> res;
	for (int i = 0; i < coef.size(); ++i) {
		z = z * by + coef[i];
		res.push_back(z);
	}
	if (res.back() == 0) {
		res.pop_back();
		return make_pair(true, res);
	} else {
		return make_pair(false, vector<int>());
	}
}

void sgn_print(int a) {
	if (a > 0)
		printf("+%d", a);
	else if (a < 0)
		printf("-%d", -a);
	else
		assert(false);
}

bool try_it(vector<int> &coef, int div) {
	pair<bool, vector<int> > res = horner(coef, div);
	if (res.first == true) {
		coef = res.second;
		printf("(x");
		sgn_print(-div);
		printf(")");
		return true;
	}
	return false;
}

int main() {
	vector<int> coef(5);
	coef[0] = 1;
	for (int i = 1; i < 5; ++i) {
		cin >> coef[i];
	}
	for (int div = 1; div <= 10000; ++div) {
		while (try_it(coef, div)) continue;
		while (try_it(coef, -div)) continue;
	}
	if (coef.size() > 1) {
		printf("(");
		reverse(coef.begin(), coef.end());
		for (int i = coef.size() - 1; i >= 0; --i) {
			if (coef[i] == 0)
				continue;
			sgn_print(coef[i]);
			if (i > 0)
				printf("x^%d", i);
		}
		printf(")");
	}
	puts("");
	return 0;
}