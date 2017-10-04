#include <iostream>
#include <cstdio>
#include <algorithm>
#define abs(x) ((x > 0) ? x : (-x))

using namespace std;

const int MAXN = 131072;

struct data { int val, idx, idx_in_sorted, ab; } numb[MAXN];

bool cmp1(data a, data b) {
    return a.ab < b.ab;
    }

bool cmp2(data a, data b) {
    return a.idx < b.idx;
    }

int cnt[100005];
int itr[MAXN << 1];

int q;
int __gcd(int a, int b) {
    if(a == 0) return b;
    if(b == 0) return a;

    q = a % b;
    while(b)
        q = a % b,
        a = b,
        b = q;

    return a;
    }

void upd(int i, int a) {
    itr[i] = a, i >>= 1;
    int l;

    while(i) l = (i << 1), itr[i] = __gcd(itr[l], itr[l + 1]), i >>= 1;
    }

int n;

int main() {
    scanf("%d", &n);

    char c;
    int i, d;

    for(i=0; i<n; i++)  {
        scanf("\n%c%d", &c, &d);
        if(c == '-') d = -d;
        numb[i].val = d;
        numb[i].idx = i;
        numb[i].ab = abs(d);
        }

    sort(numb, numb + n, cmp1);

    int t = 0;
    for(i=1; i<n; i++)
    {
    if( numb[i].ab != numb[i - 1].ab ) t++;
    numb[i].idx_in_sorted = t;
    }

    t++;
    int sz = 1;
    while(sz < t) sz <<= 1;

    sort(numb, numb + n, cmp2);

    for(i=0; i<n; i++)
    {
    t = numb[i].idx_in_sorted;
    if(numb[i].val < 0) { cnt[t]--; if(cnt[t] == 0) upd(t + sz, 0); }
    else { cnt[t]++; if(cnt[t] == 1) upd(t + sz, numb[i].val); }

    if(itr[1]) printf("%d\n", itr[1]);
    else printf("1\n");
    }

    return 0;
    }
