#include <cstdio>
#include <cstring>

int stamps[4098], n, s;
unsigned int dyn[16384];

inline unsigned int min(unsigned int a, unsigned int b) {
	return a < b ? a : b;
}

int main() {
	scanf("%d%d", &s, &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", stamps+i);
		if(stamps[i] > s) {
			--n;
			--i;
		}
	}
	
	int cmin = 1<<20, j, csum, cstep;
	memset(dyn, 0xFF, sizeof(dyn));
	dyn[0] = 0;
	for(int i = 0; i <= s; ++i) {
		if(dyn[i] <= cmin) {
			cstep = dyn[i]+1;
			
			for(j = 0; j < n; ++j) {
				csum = i+stamps[j];
				
				if(csum == s) {
					cmin = min(cmin, cstep);
				}
				
				dyn[csum] = min(dyn[csum], cstep);
			}
		}
	}
	printf("%d\n", cmin);
	return 0;
}
