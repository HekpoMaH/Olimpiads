/*
ID: espr1t
TASK: Cards
KEYWORDS: Hard, Dynamic Programming
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

int hand[MAX], deck[MAX], n;
int suitPoints[MAX], rankPoints[MAX];
int dyn[MM], comb[60][6];

int sp[4][4][4][4][4], rp[16][16][16][16][16];
inline int getPoints() {
    return sp[hand[0] & 3][hand[1] & 3][hand[2] & 3][hand[3] & 3][hand[4] & 3] +
           rp[hand[0] >> 2][hand[1] >> 2][hand[2] >> 2][hand[3] >> 2][hand[4] >> 2];
}

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
        int at = i;
		hand[at] = deck[idx];
		for (; at > 0 && hand[at] > hand[at - 1]; at--)
		    swap(hand[at], hand[at - 1]);
		for (; at < 4 && hand[at] < hand[at + 1]; at++)
		    swap(hand[at], hand[at + 1]);
		ans = max(ans, getPoints() + recurse(idx + 1));		
		memcpy(hand, save, sizeof(hand));
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

int maxCount(int a[5]) {
    int ans = 0;
    for (int i = 0; i < 5; i++) {
        int cur = 0;
        for (int c = i; c < 5; c++)
            if (a[i] == a[c]) cur++;
        ans = max(ans, cur);
    }
    return ans;
}

void precalc() {
    for (int i = 0; i < 60; i++)
        for (int c = 0; c < 6; c++)
            comb[i][c] = getComb(i, c);

    int a[5];
	for (a[0] = 0; a[0] < 13; a[0]++)
        for (a[1] = 0; a[1] < 13; a[1]++)
            for (a[2] = 0; a[2] < 13; a[2]++)
                for (a[3] = 0; a[3] < 13; a[3]++)
                    for (a[4] = 0; a[4] < 13; a[4]++)
                        rp[a[0]][a[1]][a[2]][a[3]][a[4]] = rankPoints[maxCount(a)];

	for (a[0] = 0; a[0] < 4; a[0]++)
        for (a[1] = 0; a[1] < 4; a[1]++)
            for (a[2] = 0; a[2] < 4; a[2]++)
                for (a[3] = 0; a[3] < 4; a[3]++)
                    for (a[4] = 0; a[4] < 4; a[4]++)
                        sp[a[0]][a[1]][a[2]][a[3]][a[4]] = suitPoints[maxCount(a)];
}

int solve() {
    precalc();
	sort(hand, hand + 5);
	reverse(hand, hand + 5);
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
//    in = fopen("Cards.in", "rt"); out = fopen("Cards.out", "wt");

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
    return 0;
}
