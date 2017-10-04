/*
ID: espr1t
LANG: C++
TASK: EllysCards
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
int perm;
Card hand[MAX], deck[MAX];
int suitPoints[MAX], cntSuit[MAX];
int rankPoints[MAX], cntRank[MAX];
int dyn[MAX][MAX][MAX][MAX];
int pre[5][5][6][128][6];
int fact[5] = {1, 1, 2, 6, 24};


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
	if (dist > 6) swap(idx1, idx2), dist = 13 - dist;

	/*
	int perm = 0;
	for (int i = 0; i < 4; i++)
		for (int c = i + 1; c < 5; c++)
			if (hand[i].idx > hand[c].idx) perm += fact[4 - i];
	*/

	Card nhand[5];
	for (int i = 0; i < 5; i++)
		nhand[i] = hand[pre[idx1][idx2][dist][perm][i]];
	perm = pre[idx1][idx2][dist][perm][5];
	memcpy(hand, nhand, sizeof(hand));
}

int recurse(int idx) {
	if (idx >= n) return 0;
	if (dyn[hand[0].idx][hand[1].idx][hand[2].idx][hand[3].idx] != -1)
		return dyn[hand[0].idx][hand[1].idx][hand[2].idx][hand[3].idx];
	
	int ans = 0;
	Card save[5];
	int lastPerm = perm;
	memcpy(save, hand, sizeof(save));

	for (int i = 0; i < 5; i++) {
		cntSuit[hand[i].suit]--; cntRank[hand[i].rank]--;
		cntSuit[deck[idx].suit]++; cntRank[deck[idx].rank]++;
		
		for (int c = 0; c < 5; c++) {
			if (c < i && hand[c].idx > hand[i].idx) perm -= fact[4 - c];
			if (c > i && hand[i].idx > hand[c].idx) perm -= fact[4 - i];
		}
		hand[i] = deck[idx];
		for (int c = 0; c < 5; c++) {
			if (c < i && hand[c].idx > hand[i].idx) perm += fact[4 - c];
			if (c > i && hand[i].idx > hand[c].idx) perm += fact[4 - i];
		}
		encode();

		int maxSuit = cntSuit[0];
		for (int c = 1; c < 4; c++)
			maxSuit = max(maxSuit, cntSuit[c]);
		
		int maxRank = cntRank[hand[0].rank];
		for (int c = 1; c < 5; c++)
			maxRank = max(maxRank, cntRank[hand[c].rank]);
		
		ans = max(ans, suitPoints[maxSuit] + rankPoints[maxRank] + recurse(idx + 1));
		
		perm = lastPerm;
		memcpy(hand, save, sizeof(hand));
		cntSuit[deck[idx].suit]--; cntRank[deck[idx].rank]--;
		cntSuit[hand[i].suit]++; cntRank[hand[i].rank]++;
	}
	return dyn[hand[0].idx][hand[1].idx][hand[2].idx][hand[3].idx] = ans;
}

void precalc() {
	for (int c1 = 0; c1 < 5; c1++) {
		for (int c2 = 0; c2 < 5; c2++) if (c1 != c2) {
			for (int dist = 1; dist <= 6; dist++) {
				int v[5];
				for (int i = 0; i < 5; i++) v[i] = i;
				do {
					int perm = 0;
					for (int i = 0; i < 4; i++)
						for (int c = i + 1; c < 5; c++)
							if (v[i] > v[c]) perm += fact[4 - i];

					int idx[3] = {0, 0, 0}, at = 0;
					for (int i = 0; i < 5; i++)
						if (i != c1 && i != c2) idx[at++] = i;
					
					if (v[idx[1]] < v[idx[0]]) swap(idx[0], idx[1]);
					if (v[idx[2]] < v[idx[1]]) swap(idx[1], idx[2]);
					if (v[idx[1]] < v[idx[0]]) swap(idx[0], idx[1]);
					
					swap(idx[0], idx[(dist - 1) >> 1]);
					if ((v[idx[1]] < v[idx[2]]) ^ (dist & 1)) swap(idx[1], idx[2]);

					pre[c1][c2][dist][perm][0] = c1;
					for (int i = 0; i < 3; i++)
						pre[c1][c2][dist][perm][i + 1] = idx[i];
					pre[c1][c2][dist][perm][4] = c2;

					int nperm = 0;
					int vv[5];
					for (int i = 0; i < 5; i++)
						vv[i] = v[pre[c1][c2][dist][perm][i]];
					for (int i = 0; i < 4; i++)
						for (int c = i + 1; c < 5; c++)
							if (vv[i] > vv[c]) nperm += fact[4 - i];
					pre[c1][c2][dist][perm][5] = nperm;
					
				} while(next_permutation(v, v + 5));
			}
		}
	}
}

int solve() {
	precalc();
	memset(cntSuit, 0, sizeof(cntSuit));
	memset(cntRank, 0, sizeof(cntRank));
	
	for (int i = 0; i < 5; i++) {
		cntSuit[hand[i].suit]++;
		cntRank[hand[i].rank]++;
	}

	perm = 0;
	for (int i = 0; i < 4; i++)
		for (int c = i + 1; c < 5; c++)
			if (hand[i].idx > hand[c].idx) perm += fact[4 - i];
	encode();
	memset(dyn, -1, sizeof(dyn));
	return recurse(0);
}

Card getCard() {
    char suits[MAX] = "SDHC";
    char ranks[MAX] = "23456789TJQKA";

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
