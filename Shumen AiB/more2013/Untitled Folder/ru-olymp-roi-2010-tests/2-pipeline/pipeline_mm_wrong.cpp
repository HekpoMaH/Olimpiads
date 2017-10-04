#include <string>
#include <climits>
#include <cstdio>
#include <ctime>
#include <queue>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>

#include <set>
#include <iostream>
#include <cassert>
#include <utility>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

typedef long long li;

const int N = 2000;

int n, m, t;
int deg[N];
vector<int> next[N];
bool used[N];
bool edge[200000];

bool cmp(int x, int y)
{
    return deg[x] > deg[y] ? true : (deg[x] == deg[y] && x < y);
}

set<pair<int, int> > e;

int main()
{
    freopen("pipeline.in", "rt", stdin);
    freopen("pipeline.out", "wt", stdout);

    scanf("%d %d %d", &n, &m, &t);

    forn(i, m)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        a--, b--;
        next[a].push_back(i);
        next[b].push_back(i);
    }

    forn(i, n)
        deg[i] = next[i].size();

    vector<int> id(n);
    forn(i, n)
        id[i] = i;

    sort(id.begin(), id.end(), cmp);

    while (clock() < 1.75 * CLOCKS_PER_SEC)
    {
        //cerr << "." << endl;

        forn(i, n)
            used[i] = false;
        forn(i, m)
            edge[i] = true;

        int limit = 20 + min(rand() % 65, rand() % 65);
        int edgeCount = m;
        int usedCount = 0;

        forn(i, n)
        {
            if (edgeCount == 0 || usedCount > t)
                break;

            if (rand() % 100 < limit)
            {
                bool need = false;

                forn(j, next[i].size())
                {
                    if (edge[next[i][j]])
                    {
                        need = true;
                        break;
                    }
                }

                if (need)
                {
                    usedCount++;
                    used[i] = true;

                    forn(j, next[i].size())
                    {   
                        if (edge[next[i][j]])
                        {
                            edgeCount--;
                            edge[next[i][j]] = false;
                        }
                    }
                }
            }
        }

        if (usedCount <= t && edgeCount == 0)
        {
            forn(i, n)
                if (usedCount < t && !used[i])
                {
                    used[i] = true;
                    usedCount++;
                }
            printf("Yes\n");
            forn(i, n)
                if (used[i])
                    printf("%d ", i + 1);
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}
