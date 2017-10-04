#include <cstdio>

int a, b;
char quot[1024], qn;
char rem[1024];

long long k;
int p;

void solve() {
	int ctry = a * 10, cres, crem;
	for(int i = 0; i < 1024; ++i) {
		cres = ctry / b;
		//printf("%d", cres);
		quot[qn++] = cres;
		crem = ctry - cres*b;
		if(rem[ctry]) {
			// found cycle
			int cs = rem[ctry]-1;
			int cl = qn - rem[ctry];
			//printf("%d %d\n", cs, cl);
			// print all pre-cycle digits
			p -= cs-k > 0 ? cs-k : 0;
			for(unsigned long long ki = k; ki < cs; ++ki) {
				printf("%d", quot[ki]);
			}
			// found where we are at the cycle
			k -= cs;
			int cp = k % cl;
			p -= cl-cp > 0 ? cl-cp : 0;
			for(int j = cp; j < cl; ++j) {
				printf("%d", quot[cs + j]);
			}
				
			// print cycles
			int j = 0;
			while(p) {
				printf("%d", quot[cs + j]);
				j = (j+1)%cl;
				--p;
			}
			break;
		}
		rem[ctry] = qn;
		ctry = crem*10;
	}
}

int main() {
	scanf("%d%d", &a, &b);
	scanf("%lld%d", &k, &p);
	--k;
	solve();
	return 0;
}
