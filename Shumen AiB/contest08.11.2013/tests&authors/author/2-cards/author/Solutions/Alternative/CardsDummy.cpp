/*
ID: espr1t
TASK: Cards
KEYWORDS: Dynamic Programming
*/

#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;
FILE* in; FILE* out;

const int MAX = 52;

struct Card {
	int rank, suit, idx;
};

int n;
Card hand[MAX], deck[MAX];
int suitPoints[MAX], cntSuit[MAX];
int rankPoints[MAX], cntRank[MAX];
int dyn[MAX][MAX][MAX][MAX][MAX];

int recurse(int idx) {
	if (idx >= n) return 0;
	if (dyn[hand[0].idx][hand[1].idx][hand[2].idx][hand[3].idx][hand[4].idx] != -1)
		return dyn[hand[0].idx][hand[1].idx][hand[2].idx][hand[3].idx][hand[4].idx];
	
	int ans = 0;
	for (int i = 0; i < 5; i++) {
		Card save = hand[i];

		cntSuit[hand[i].suit]--; cntRank[hand[i].rank]--;
		hand[i] = deck[idx];
		cntSuit[hand[i].suit]++; cntRank[hand[i].rank]++;

		int maxSuit = cntSuit[0];
		for (int c = 1; c < 4; c++)
			maxSuit = max(maxSuit, cntSuit[c]);
		
		int maxRank = cntRank[hand[0].rank];
		for (int c = 1; c < 5; c++)
			maxRank = max(maxRank, cntRank[hand[c].rank]);
		
		ans = max(ans, suitPoints[maxSuit] + rankPoints[maxRank] + recurse(idx + 1));
		
		cntSuit[hand[i].suit]--; cntRank[hand[i].rank]--;
		hand[i] = save;
		cntSuit[hand[i].suit]++; cntRank[hand[i].rank]++;
	}
	return dyn[hand[0].idx][hand[1].idx][hand[2].idx][hand[3].idx][hand[4].idx] = ans;
}

int solve() {
	memset(cntSuit, 0, sizeof(cntSuit));
	memset(cntRank, 0, sizeof(cntRank));
	for (int i = 0; i < 5; i++) {
		cntSuit[hand[i].suit]++;
		cntRank[hand[i].rank]++;
	}
	memset(dyn, -1, sizeof(dyn));
	return recurse(0);
}

Card getCard() {
    char suits[] = "SDHC";
    char ranks[] = "23456789TJQKA";
	
    char card[4];
    fscanf(in, "%s", card);

    Card ret;
	for (int i = 0; i < 4; i++)
		if (card[1] == suits[i]) ret.suit = i;
	for (int i = 0; i < 13; i++)
		if (card[0] == ranks[i]) ret.rank = i;
	ret.idx = ret.rank + ret.suit * 13;
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
