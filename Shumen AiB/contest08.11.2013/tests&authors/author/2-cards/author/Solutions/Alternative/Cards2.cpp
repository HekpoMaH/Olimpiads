/*
ID: espr1t
TASK: Cards
KEYWORDS: Dynamic Programming
*/

#include <cstdio>
#include <ctime>
#include <cstring>
#include <algorithm>

using namespace std;
FILE* in; FILE* out;

const int MAX = 52;

int n;
int hand[MAX], deck[MAX];
int suitPoints[MAX], cntSuit[MAX];
int rankPoints[MAX], cntRank[MAX];
int dyn[MAX][MAX][MAX][MAX];
		
void encode() {
	int idx1 = -1, idx2 = -1, suit = 0;
	while (cntSuit[suit] < 2) suit++;
	for (int i = 0; i < 5; i++) {
	    if ((hand[i] & 3) == suit) {
    		if (idx1 == -1 || hand[i] < hand[idx1])
    			idx2 = idx1, idx1 = i;
    		else if (idx2 == -1 || hand[i] < hand[idx2])
    			idx2 = i;
	    }
	}

	int dist = (hand[idx2] - hand[idx1]) >> 2;
	if (dist > 6) swap(idx1, idx2), dist = 13 - dist;
	swap(hand[idx2], hand[4]);
	if (idx1 == 4) idx1 = idx2;
	swap(hand[idx1], hand[0]);

	if (hand[2] < hand[1]) swap(hand[1], hand[2]);
	if (hand[3] < hand[2]) swap(hand[2], hand[3]);
	if (hand[2] < hand[1]) swap(hand[1], hand[2]);
	
	swap(hand[1], hand[(dist + 1) >> 1]);
	if ((hand[2] < hand[3]) ^ (dist & 1)) swap(hand[2], hand[3]);
}

int recurse(int idx) {
	if (idx >= n) return 0;
	if (dyn[hand[0]][hand[1]][hand[2]][hand[3]] != -1)
		return dyn[hand[0]][hand[1]][hand[2]][hand[3]];
	int ans = 0;

	int save[5];
	memcpy(save, hand, sizeof(save));

	for (int i = 0; i < 5; i++) {
		cntSuit[hand[i] & 3]--; cntRank[hand[i] >> 2]--;
		cntSuit[deck[idx] & 3]++; cntRank[deck[idx] >> 2]++;			

		hand[i] = deck[idx];
		encode();
		int maxSuit = cntSuit[0];
		for (int c = 1; c < 4; c++)
			maxSuit = max(maxSuit, cntSuit[c]);
		int maxRank = cntRank[hand[0] >> 2];
		for (int c = 1; c < 5; c++)
			maxRank = max(maxRank, cntRank[hand[c] >> 2]);
		ans = max(ans, suitPoints[maxSuit] + rankPoints[maxRank] + recurse(idx + 1));
		
		memcpy(hand, save, sizeof(hand));
		cntSuit[hand[i] & 3]++; cntRank[hand[i] >> 2]++;
		cntSuit[deck[idx] & 3]--; cntRank[deck[idx] >> 2]--;
	}
	return dyn[hand[0]][hand[1]][hand[2]][hand[3]] = ans;
}

int solve() {
    memset(cntSuit, 0, sizeof(cntSuit));
    memset(cntRank, 0, sizeof(cntRank));
	for (int i = 0; i < 5; i++) {
		cntSuit[hand[i] & 3]++;
		cntRank[hand[i] >> 2]++;
	}
	encode();
	memset(dyn, -1, sizeof(dyn));
	return recurse(0);
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
