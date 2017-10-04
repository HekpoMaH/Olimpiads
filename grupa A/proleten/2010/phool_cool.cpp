#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
using namespace std;

double get_angle(double a, double b, double c) {
	return acos((a*a+b*b-c*c)/(2*a*b));
}
double get_side(double a, double b, double alpha) {
	return sqrt(a*a+b*b-2*a*b*cos(alpha));
}
bool valid(double a, double b, double c) {
	return
		a < b+c &&
		b < a+c &&
		c < a+b;
}
bool valid(double a, double b, double c, double d) {
	return
		a < b+c+d &&
		b < a+c+d &&
		c < a+b+d &&
		d < a+b+c;
}

double attempt(int a, int b, int c, int d) {
	if(!valid(a, b, c, d))
		return -1;
	if(!valid(a, b+c, d))
		return -1;
	double alpha = get_angle(b+c, a, d);
	double cut = get_side(a, b, alpha);
	return cut;
}

#define EPS 0.00001
double dabs(double a) {
	return a >= 0 ? a : -a;
}
bool deq(double a, double b) {
	return dabs(a-b) < EPS;
}

set<string> cuts;
void add(double cut) {
	if(cut == -1)
		return;
	char buf[16];
	sprintf(buf, "%.02lf", cut);
	cuts.insert(string(buf));
}

int main() {
	int s[4];
	int ind[4] = {0, 1, 2, 3};

	scanf("%d%d%d%d", s+0, s+1, s+2, s+3);

	add(attempt(s[ind[0]], s[ind[1]], s[ind[2]], s[ind[3]]));
	while(next_permutation(ind, ind+4)) {
		add(attempt(s[ind[0]], s[ind[1]], s[ind[2]], s[ind[3]]));
	}

	printf("%d\n", cuts.size());
	for(set<string>::iterator i = cuts.begin(); i != cuts.end(); ++i) {
		printf("%s\n", i->c_str());
	}
	return 0;
}
