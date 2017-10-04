#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <set>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cassert>
#include <utility>

using namespace std;

#define EPS 1E-8

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forv(i, a) for (int i = 0; i < int(a.size()); i++)
#define fors(i, a) for (int i = 0; i < int(a.length()); i++)
#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
#define VI vector<int>
#define VS vector<string>

#define norm(a) sort(all(a)); a.erase(unique(all(a)), a.end());
#define num(a, v) (int)(lower_bound(all(a), v) - a.begin())

#define C_IN_FILE "pipeline.in"
#define C_OUT_FILE "pipeline.out"

const int NMAX = 2000;
const int KMAX = 55;
typedef vector<size_t> Graph[NMAX];

size_t n, m, k;

Graph graph;
Graph greenGraph;

size_t greenD[NMAX];

size_t largeDegreeNumber;

struct ListElement
{
    int prev, next;
};

ListElement elements[NMAX + KMAX + 5];
size_t listTop[KMAX + 5];
size_t listSize[KMAX + 5];

bool getted[NMAX];

void outdata()
{
}

void createGreenGraph()
{
    largeDegreeNumber = 0;
    forn(i, n) {
        greenD[i] = 0;
        vector<size_t>& inc = graph[i];
        if (inc.size() <= k) {
            forv(j, inc) {
                if (graph[inc[j]].size() <= k) {
                    ++greenD[i];
                    greenGraph[i].pb(inc[j]);
                }                
            }
        } else {
            getted[i] = true;
            ++largeDegreeNumber;
        }
    }
}

inline void del(size_t listId, size_t elementId)
{
    if (listId == 0) return ;
    --listSize[listId];
    ListElement& cur = elements[elementId];
    elements[cur.prev].next = cur.next;
    if (cur.next != -1) {
        elements[cur.next].prev = cur.prev;
    }
    cur.prev = cur.next = -1;
}

inline void add(size_t listId, size_t elementId)
{
    if (listId == 0) return ;
    ++listSize[listId];
    ListElement& cur = elements[elementId];
    cur.prev = listTop[listId];
    cur.next = elements[listTop[listId]].next;

    if (cur.next != -1) {
        elements[cur.next].prev = elementId;
    }
    elements[cur.prev].next = elementId;
}

void createList()
{
    forn(i, KMAX + 5) {
        listSize[i] = 0;
        listTop[i] = n + i;
        elements[n + i].next = -1;
    }
    forn(i, n) {
        add(greenD[i], i);
    }    
}

void get(int v, int dir) {
    getted[v] = dir == 1;
	if (dir == 1) {
		del(greenD[v], v);
	} else {
		add(greenD[v], v);
	}
    vector<size_t>& inc = greenGraph[v];
	forv(i, inc) {
		if (!getted[inc[i]]) {
			del(greenD[inc[i]], inc[i]);
			greenD[inc[i]] -= dir;
			add(greenD[inc[i]], inc[i]);
		} else {
			greenD[inc[i]] -= dir;
		}
	}
}

void output()
{
    cout << "Yes" << endl;
    size_t getCount = k;
    forn(i, n) if (getted[i]) {
        --getCount;
        cout << i + 1 << " ";
    }
    forn(i, n) if (getCount && !getted[i]) {
        --getCount;
        cout << i + 1 << " ";
    }
    cout << endl;
}

void bruteForce(size_t curK)
{
    for(size_t i = k; i > curK; --i) {
        if (listSize[i] > 0) {
			if (curK == 0) {
				return ;
			}
            int v = elements[listTop[i]].next;
            get(v, 1);
            bruteForce(curK - 1);
            get(v, -1);
            return ;
        }
    }
    if (curK == 0) {
        output();
        exit(0);
    }
    if (listSize[1] > 0) {
        int v = elements[listTop[1]].next;
        size_t sosed = 0;
        vector<size_t>& inc = greenGraph[v];
        forv(i, inc) if (!getted[inc[i]]) {
            sosed = inc[i];
            break;
        }
        get(sosed, 1);
        bruteForce(curK - 1);
        get(sosed, -1);
        return ;
    }

    for(size_t i = curK; i > 1; --i) {
        if (listSize[i] > 0) {
            int v = elements[listTop[i]].next;
            get(v, 1);
            bruteForce(curK - 1);
            get(v, -1);
            assert(greenD[v] == i);
            if (i > 2) {
                vector<size_t>& inc = greenGraph[v];
                vector<size_t> notGettedInc;
                notGettedInc.reserve(inc.size());
                size_t degree = greenD[v];
                forv(i, inc) if (!getted[inc[i]]) {
                    get(inc[i], 1);
                    notGettedInc.pb(inc[i]);
                }
                bruteForce(curK - degree);
                forv(i, notGettedInc) {
                    get(notGettedInc[i], -1);
                }
            }
            return ;
        }
    }
	bruteForce(0);
}

void solve()
{
    memset(getted, 0, sizeof getted);
    createGreenGraph();
    createList();
    if (k < largeDegreeNumber) {
        cout << "No" << endl;
        exit(0);
    } else {
        size_t newK = k - largeDegreeNumber;
        bruteForce(newK);
    }
    cout << "No" << endl;
}

void check()
{
    assert(k <= n && n <= 2000);
    assert(1 <= m && m <= 100000);
    forn(i, n) {
        assert(graph[i].size() > 0);
        sort(all(graph[i]));
        assert(unique(all(graph[i])) == graph[i].end());
    }
}

void readdata()
{
    cin >> n >> m >> k;
    forn(i, m) {
        size_t x, y;
        cin >> x >> y;
        --x;
        --y;
        graph[x].pb(y);
        graph[y].pb(x);
    }
    check();
}

int main() {
    srand(123);
    freopen(C_IN_FILE, "rt", stdin);
    freopen(C_OUT_FILE, "wt", stdout);
	readdata();
	solve();
	outdata();
	return 0;
}
