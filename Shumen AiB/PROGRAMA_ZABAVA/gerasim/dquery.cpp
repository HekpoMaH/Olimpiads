#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 30001;
const int MAXQ = 200001;
const int MAX_VAL = 1000001;

int a[MAXN];
int it[MAXN];
int ans[MAXQ];
int n, q;

int last[MAX_VAL];
int cnt[MAX_VAL];

struct Query {
    int l, r;
    int idx;
    };

Query qu[MAXQ];
Query q_copy[MAXQ];

bool cmp(Query a, Query b) {
    return a.r < b.r;
    }

void update(int ind, int val) {
    if(ind)
    while(ind <= n)
        it[ind] += val,
        ind += (ind & -ind);
    }

int query(int ind) {
    if(ind == 0) return 0;

    int ret = 0;
    while(ind > 0)
        ret += it[ind],
        ind -= (ind & -ind);

    return ret;
    }

void counting_sort() {
    int i;
    for(i=1; i<=q; i++) cnt[qu[i].r]++;
    for(i=1; i<=MAXN; i++) cnt[i] += cnt[i - 1];
    for(i=1; i<=q; i++) q_copy[cnt[qu[i].r]--] = qu[i];
    memcpy(qu, q_copy, sizeof(q_copy));
    }

int main() {
    scanf("%d", &n);

    int i;
    for(i=1; i<=n; i++) scanf("%d", &a[i]);

    scanf("%d", &q);
    for(i=1; i<=q; i++) scanf("%d%d", &qu[i].l, &qu[i].r),
                        qu[i].idx = i;

    counting_sort();

    int j;
    int sum_r = 0;

    for(i=1; i<=q; i++)
    {
    for(j=qu[i-1].r + 1; j<=qu[i].r; j++)
            update(last[a[j]], -1),
            last[a[j]] = j,
            update(last[a[j]], 1);

    if(qu[i].r != qu[i-1].r) sum_r = query(qu[i].r);
    ans[qu[i].idx] = sum_r - query(qu[i].l - 1);
    }

    for(i=1; i<=q; i++) printf("%d\n", ans[i]);
    return 0;
    }
