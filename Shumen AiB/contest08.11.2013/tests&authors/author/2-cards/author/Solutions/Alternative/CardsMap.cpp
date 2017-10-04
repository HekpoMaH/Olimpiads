/*
ID: espr1t
TASK: Cards
KEYWORDS: Dynamic Programming
*/

#include <cstdio>
#include <ctime>
#include <map>
#include <cstdlib>
#include <cstring>

const int MAX = 52;

using namespace std;
FILE* in; FILE* out;

struct HashElement {
	long long mask;
	int ans;
};

int n;
int hand[MAX], deck[MAX];
int suitPoints[MAX], cntSuit[MAX];
int rankPoints[MAX], cntRank[MAX];
map < long long, int> dyn;

int recurse(int idx, long long mask) {
	if (idx >= n) return 0;
	if (dyn.find(mask) != dyn.end())
		return dyn[mask];
	
	int ans = 0;
	for (int i = 0; i < 5; i++) {
		cntSuit[hand[i] & 3]--; cntRank[hand[i] >> 2]--;
		cntSuit[deck[idx] & 3]++; cntRank[deck[idx] >> 2]++;
		long long nmask = ((mask ^ (1LL << hand[i])) | (1LL << deck[idx]));

		int save = hand[i];
		hand[i] = deck[idx];
		int maxSuit = cntSuit[0];
		for (int c = 1; c < 4; c++)
			maxSuit = max(maxSuit, cntSuit[c]);
		int maxRank = cntRank[hand[0] >> 2];
		for (int c = 1; c < 5; c++)
			maxRank = max(maxRank, cntRank[hand[c] >> 2]);
		
		ans = max(ans, suitPoints[maxSuit] + rankPoints[maxRank] + recurse(idx + 1, nmask));
		
		hand[i] = save;
		cntSuit[hand[i] & 3]++; cntRank[hand[i] >> 2]++;
		cntSuit[deck[idx] & 3]--; cntRank[deck[idx] >> 2]--;
	}
	return dyn[mask] = ans;
}

int solve() {
	dyn.clear();
	memset(cntSuit, 0, sizeof(cntSuit));
	memset(cntRank, 0, sizeof(cntRank));

	for (int i = 0; i < 5; i++) {
		cntSuit[hand[i] & 3]++;
		cntRank[hand[i] >> 2]++;
	}
	
	long long mask = 0;
	for (int i = 0; i < 5; i++)
		mask |= (1LL << hand[i]);
	return recurse(0, mask);
}

int getCard() {
    char suits[] = "SDHC";
    char ranks[] = "23456789TJQKA";

    char card[4];
    fscanf(in, "%s", card);

	int ret = 0;
	for (int i = 0; i < 4; i++)
		if (card[1] == suits[i]) ret |= i;
	for (int i = 0; i < 13; i++)
		if (card[0] == ranks[i]) ret |= (i << 2);
	return ret;
}

int main(void) {
	in = stdin; out = stdout;
	in = fopen("Cards.in", "rt"); out = fopen("Cards.out", "wt");

	int numTests;
	fscanf(in, "%d", &numTests);
	for (int test = 0; test <= numTests; test++) {
		unsigned sTime = clock();
		
		fscanf(in, "%d", &n);
		for (int i = 1; i <= 4; i++)
		    fscanf(in, "%d", &rankPoints[i]);
		for (int i = 1; i <= 5; i++)
		    fscanf(in, "%d", &suitPoints[i]);
		for (int i = 0; i < 5; i++)
		    hand[i] = getCard();
		for (int i = 0; i < n; i++)
		    deck[i] = getCard();
		
		fprintf(out, "%d\n", solve());
		fprintf(stderr, "Execution time for test %d is: %.3lf seconds.\n",
			test, (double)(clock() - sTime) / CLOCKS_PER_SEC);
	}
	return 0;
}
