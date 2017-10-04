/*
plates.cpp
Solution by hashing and storing hash values in a set
*/
#include <stdio.h>
#include <stdlib.h>
#include <set>
using namespace std;

/*
hashing defines
*/
#define num long
#define M 1000001L
#define P 907L
#define Q 1009L
#define MAXN 32
int n;
num PQ[MAXN][MAXN];

int a[MAXN][MAXN];

num hash(){
	int i, j, ip, jp;
	num res = 0;
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			if(a[i][j]){
				ip = n - 1 - i;
				jp = n - 1 - j;
				res += PQ[i][j] + PQ[j][i] + PQ[ip][j] + PQ[j][ip];
				res %= M;
				res += PQ[i][jp] + PQ[jp][i] + PQ[ip][jp] + PQ[jp][ip];
				res %= M;
			}
	return res;
}



void initPQ(){
	//PQ[i][j] is P^i Q^j
	int i, j;
	PQ[0][0] = 1;
	for(i = 1; i < MAXN; i++){
		PQ[i][0] = P * PQ[i - 1][0];
		PQ[i][0] %= M;
	}
	for(j = 1; j < MAXN; j++){
		for(i = 0; i < MAXN; i++){
			PQ[i][j] = Q * PQ[i][j - 1];
			PQ[i][j] %= M;
		}
	}
}


int main(){
	/*
	Elementary 2D hash function:
	H(A) = sum A[i][j]P^i Q^j mod M
	but we must not distinguish between rotations and flipping, so it really should be
	H(A) + H(A rot 90) + H(A rot 180) + H(A rot 270) +H(A'
	H(A) = sum Aij*(P^i Q^j + P^j Q^i + P^(n - 1 - i)Q^())
	H(A) = sum Aij*(P^i Q^j + P^j Q^i + P^(n - 1 - i) Q^j + P^j Q^(n - 1 - i) + P^i Q^(n - 1 - i))
	*/
	initPQ();
	set<num> s;
	char ch;
	int p, i, j, m;
	scanf("%d %d", &m, &n);
	for(p = 0; p < m; p++){
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++){
				scanf(" %c", &ch);
				a[i][j] = ch - '0';
			}
		s.insert(hash());
	}
	printf("%d\n", s.size());
	return 0;
}