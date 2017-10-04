#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>
#include <map>

using namespace std;

const int MAXN = 100000;
const int MAXD = 1000000000;

class Passenger
{
public:
	int l, r, t, id;
};

int n, k, m;
Passenger psg[MAXN];

void Load()
{
	scanf("%d%d%d", &n, &m, &k);
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d%d%d", &psg[i].l, &psg[i].r, &psg[i].t);
		psg[i].id = i;
	}
}

class Psg2
{
public:
	int r, t, id;
};

bool operator<(const Psg2 &a, const Psg2 &b)
{
	if (a.r < b.r) return true;
	if (a.r > b.r) return false;
	if (a.t > b.t) return true;
	if (a.t < b.t) return false;
	return a.id < b.id;
}

bool operator<(const Passenger &a, const Passenger &b)
{
	return a.r < b.r;
}

bool CompareP(const Passenger &a, const Passenger &b)
{
	return a.l < b.l;
}

vector<Passenger> p;

int result[MAXN];

void Solve()
{
	memset(result, 0, sizeof(result));
	p.clear();
	int i;
	for (i = 0; i < n; i++)
	{
		if (psg[i].t == 1) p.push_back(psg[i]);
	}
	sort(p.begin(), p.end());
	int curday = MAXD;
	int cp = ((int)p.size()) - 1;
	while (cp >= 0)
	{
		curday = p[cp].r;
		set<pair<int, int> > curpass;
		curpass.clear();
		while (cp >= 0 && p[cp].r == curday) 
		{
			curpass.insert(make_pair(p[cp].l, p[cp].id));
			cp--;
		}
		while (curpass.size() > 0)
		{
			int cplane = 0;
			while (cplane < k && curpass.size() > 0)
			{
				set<pair<int, int> >::iterator pp = --curpass.end();
				psg[pp->second].r = curday;
				curpass.erase(--curpass.end());
				cplane++;
			}
			curday--;
			while (cp >= 0 && p[cp].r == curday) 
			{
				curpass.insert(make_pair(p[cp].l, p[cp].id));
				cp--;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		if (psg[i].l > psg[i].r) 
		{
			printf("0\n");
			return;
		}
	}
	p.clear();
	for (i = 0; i < n; i++) p.push_back(psg[i]);
	sort(p.begin(), p.end(), CompareP);
	curday = 0;
	cp = 0;
	int ans = 0;
	while (cp < (int)p.size())
	{
		curday = p[cp].l;
		set<Psg2> curpass;
		while (cp < (int)p.size() && p[cp].l == curday)
		{
			Psg2 pp;
			pp.r = p[cp].r;
			pp.id = p[cp].id;
			pp.t = p[cp].t;
			cp++;
			curpass.insert(pp);
		}
		while (curpass.size() > 0)
		{
			int cplane = 0;
			while (cplane < k && curpass.size() > 0)
			{
				Psg2 curp = *curpass.begin();
				curpass.erase(curpass.begin());
				result[curp.id] = curday;
				ans++;
				cplane++;
			}
			curday++;
			while (curpass.size() > 0 && curpass.begin()->r < curday) curpass.erase(curpass.begin());
			while (cp < (int)p.size() && p[cp].l == curday)
			{
				Psg2 pp;
				pp.r = p[cp].r;
				pp.id = p[cp].id;
				pp.t = p[cp].t;
				cp++;
				curpass.insert(pp);
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		if (psg[i].t == 1 && result[i] == 0)
		{
			printf("0\n");
			return;
		}
	}
	printf("%d\n", ans);
	for (i = 0; i < n; i++) printf("%d ", result[i]);
}

int main()
{
	freopen("planes.in", "rt", stdin);
	freopen("planes.out", "wt", stdout);
	Load();
	Solve();
	return 0;
}
