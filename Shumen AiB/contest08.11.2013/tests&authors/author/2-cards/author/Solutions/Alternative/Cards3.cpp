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
int dyn[MAX][MAX][MAX][MAX];

void encode() {
	int idx1 = -1, idx2 = -1, suit = 0;
	while (cntSuit[suit] < 2) suit++;
	for (int i = 0; i < 5; i++) {
	    if (hand[i].suit == suit) {
			if (idx1 == -1 || hand[i].rank < hand[idx1].rank)
				idx2 = idx1, idx1 = i;
			else if (idx2 == -1 || hand[i].rank < hand[idx2].rank)
				idx2 = i;
	    }
	}
	
	int dist = hand[idx2].rank - hand[idx1].rank;
	if (dist > 6)
		swap(idx1, idx2), dist = 13 - dist;
	swap(hand[idx2], hand[4]);
	if (idx1 == 4) idx1 = idx2;
	swap(hand[idx1], hand[0]);
	
	if (hand[2].idx < hand[1].idx) swap(hand[1], hand[2]);
	if (hand[3].idx < hand[2].idx) swap(hand[2], hand[3]);
	if (hand[2].idx < hand[1].idx) swap(hand[1], hand[2]);
	
	swap(hand[1], hand[(dist + 1) >> 1]);
	if ((hand[2].idx < hand[3].idx) ^ (dist & 1)) swap(hand[2], hand[3]);
}

int recurse(int idx) {
	if (idx >= n) return 0;
	if (dyn[hand[0].idx][hand[1].idx][hand[2].idx][hand[3].idx] != -1)
		return dyn[hand[0].idx][hand[1].idx][hand[2].idx][hand[3].idx];
	
	int ans = 0;
	Card save[5];
	memcpy(save, hand, sizeof(save));

	for (int i = 0; i < 5; i++) {
		cntSuit[hand[i].suit]--; cntRank[hand[i].rank]--;
		cntSuit[deck[idx].suit]++; cntRank[deck[idx].rank]++;

		hand[i] = deck[idx];
		encode();

		int maxSuit = cntSuit[0];
		for (int c = 1; c < 4; c++)
			maxSuit = max(maxSuit, cntSuit[c]);
		
		int maxRank = cntRank[hand[0].rank];
		for (int c = 1; c < 5; c++)
			maxRank = max(maxRank, cntRank[hand[c].rank]);
		
		ans = max(ans, suitPoints[maxSuit] + rankPoints[maxRank] + recurse(idx + 1));
		
		cntSuit[deck[idx].suit]--; cntRank[deck[idx].rank]--;
		memcpy(hand, save, sizeof(hand));
		cntSuit[hand[i].suit]++; cntRank[hand[i].rank]++;
	}
	return dyn[hand[0].idx][hand[1].idx][hand[2].idx][hand[3].idx] = ans;
}

int solve() {
    memset(cntSuit, 0, sizeof(cntSuit));
    memset(cntRank, 0, sizeof(cntRank));
	for (int i = 0; i < 5; i++) {
		cntSuit[hand[i].suit]++;
		cntRank[hand[i].rank]++;
	}
	encode();
	memset(dyn, -1, sizeof(dyn));
	return recurse(0);
}

Card getCard() {
    char suits[] = "SDHC";
    char ranks[] = "23456789TJQKA";

	Card ret;
    char card[4];
    fscanf(in, "%s", card);
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
