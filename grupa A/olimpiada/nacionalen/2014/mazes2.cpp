#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

typedef long long LL;
typedef vector< LL > VL;
typedef vector< VL > Ma3x;

const LL MOD = 1234567;

int m;
LL n;
Ma3x a;

void read() {
	cin >> m >> n;
}

void init() {
	
	a.resize(1 << m);
	for(int i = 0; i < (1 << m); i ++)
		a[i].resize(1 << m, 0);
	
	for(int mask1 = 0; mask1 < (1 << m); mask1 ++)
		for(int nxt = 0; nxt < (1 << m); nxt ++) {
			int mask2 = nxt;
			for(int i = 0; i < m; i ++)
				if(!((mask2 >> i) & 1)) {
					bool fl = false;
					for(int j = i; j < m; j ++) {
						if((mask2 >> j) & 1) break;
						if(!((mask1 >> j) & 1)) {
							fl = true;
							break;
						}
					}
					if(fl) continue;
					for(int j = i - 1; j >= 0; j --) {
						if((mask2 >> j) & 1) break;
						if(!((mask1 >> j) & 1)) {
							fl = true;
							break;
						}
					}
					if(fl) continue;
					mask2 |= (1 << i);
				}
			a[mask1][mask2] ++;
		}
}

Ma3x mult(Ma3x A, Ma3x B) {
	Ma3x C;
	
	C.resize(1 << m);
	for(int i = 0; i < (1 << m); i ++)
		C[i].resize(1 << m, 0);
	
	for(int i = 0; i < (1 << m); i ++)
		for(int j = 0; j < (1 << m); j ++)
			for(int k = 0; k < (1 << m); k ++) {
				C[i][j] += A[i][k] * B[k][j];
				if(C[i][j] >= MOD) C[i][j] %= MOD;
			}
	
	return C;
}

void print(Ma3x ma3x) {
	cout << "-----------\n";
	for(int i = 0; i < (1 << m); i ++) {
		for(int j = 0; j < (1 << m); j ++)
			cout << ma3x[i][j] << " ";
		cout << endl;
	}
	
	cout << endl;
}

Ma3x go(Ma3x base, LL pw) {
	if(pw == 1)
		return base;
	
	if(pw & 1) return mult(base, go(base, pw - 1));
	return go(mult(base, base), pw >> 1);
}

void solve() {
	for(int i = 0; i < (1 << m); i ++) {
		for(int j = 0; j < (1 << m); j ++)
			cout << a[i][j] << " ";
		cout << endl;
	}

	Ma3x res;
	res = go(a, n);
	
	LL ret = 0;
	for(int i = 0; i < (1 << m) - 1; i ++) {
		ret += res[0][i];
		if(ret >= MOD) ret -= MOD;
	}
	
	cout << ret % MOD << endl;
}

int main()
{
	read();
	init();
	solve();
	
	return 0;
}
