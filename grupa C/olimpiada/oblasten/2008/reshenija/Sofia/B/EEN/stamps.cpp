/*
NAME:	Emil Evgeniev Nikolov
SCHOOL:	SMG
TASK:	stamps
LANG:	C++
*/
#include <cstdio>

struct stamp {
	int value;
	int count;
	
	stamp(){}
	stamp(int _value, int _count) : value(_value), count(_count) {}
	
} dyn[1048576];

int s, n;
int stamps[4096];
int count;
bool used[8192];
int pl, l;

int main() {
//	freopen("stamps.in", "r", stdin);
//	freopen("stamps.out", "w", stdout);
	
	scanf("%d%d", &s, &n);
	
	count = n;
	
	for(int i = 0; i < n; ++i) {
		scanf("%d", (stamps + i));
		dyn[i] = stamp(stamps[i], 1);
	}
	
	while(true) {
		for(int i = pl, cnt = count; i < cnt; ++i) {
			for(int j = 0; j < cnt; ++j) {
				int x = dyn[i].value + dyn[j].value;
				if(used[x] != true && x <= s) {
					dyn[count++] = stamp(x, (dyn[i].count + dyn[j].count));
					used[x] = true;
				}
				if(x == s) {
					printf("%d\n", dyn[count - 1].count);
					return 0;
				}
			}
		}
	}
	
	
	
	return 0;
}
