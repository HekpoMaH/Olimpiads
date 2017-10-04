/*
ID: espr1t
TASK: Cards
KEYWORDS: Dynamic Programming
*/

#include <cstdio>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;
FILE* in; FILE* out;

const int MAX = 52;
const int MM = 2598960;

int n;
int hand[MAX], deck[MAX];
int suitPoints[MAX], cntSuit[MAX];
int rankPoints[MAX], cntRank[MAX];
int dyn[MM], comb[60][6];

inline int encode() {
    int ans = 0;
    for (int i = 0; i < 5; i++)
        ans += comb[hand[i]][5 - i];
	return ans;
}

int recurse(int idx) {
	if (idx >= n) return 0;
	int& ans = dyn[encode()];
	if (ans != -1) return ans;

    ans = 0;
    int save[5];
	memcpy(save, hand, sizeof(save));

	for (int i = 0; i < 5; i++) {
		cntSuit[hand[i] & 3]--; cntRank[hand[i] >> 2]--;
		cntSuit[deck[idx] & 3]++; cntRank[deck[idx] >> 2]++;			

        int at = i;
		hand[at] = deck[idx];
		for (; at > 0 && hand[at] > hand[at - 1]; at--)
		    swap(hand[at], hand[at - 1]);
		for (; at < 4 && hand[at] < hand[at + 1]; at++)
		    swap(hand[at], hand[at + 1]);

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
	return ans;
}

int getComb(int n, int k){
    if (n < k) return 0;
    int ans = 1;
    for (int i = 0; i < k; i++)
        ans = ans * (n - i) / (i + 1);
	return ans;
}

int solve() {
    for (int i = 0; i < 60; i++)
        for (int c = 0; c < 6; c++)
            comb[i][c] = getComb(i, c);

	memset(cntSuit, 0, sizeof(cntSuit));
	memset(cntRank, 0, sizeof(cntRank));
	
	sort(hand, hand + 5);
	reverse(hand, hand + 5);
	for (int i = 0; i < 5; i++) {
		cntSuit[hand[i] & 3]++;
		cntRank[hand[i] >> 2]++;
	}
	memset(dyn, -1, sizeof(dyn));
	return recurse(0);
}

int getCard() {
    char suits[5] = "SDHC";
    char ranks[14] = "23456789TJQKA";
    
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
