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

vector<Passenger> p;

bool operator<(const Passenger &a, const Passenger &b)
{
	return a.l < b.l;
}

int result[MAXN];

int CountAns()
{
	set<pair<int, int> > have;
	int cd = 1;
	int cp = 0;
	while (cp < p.size())
	{
		cd = p[cp].l;
		while (cp < (int)p.size() && p[cp].l == cd)
		{
			have.insert(make_pair(p[cp].r, p[cp].id));
			cp++;
		}
		while (have.size() > 0)
		{
			int cur = 0;
			while (cur < k && have.size() > 0)
			{
				result[have.begin()->second] = cd;
				have.erase(have.begin());
				cur++;
			}
			cd++;
			if (have.size() > 0 && have.begin()->first < cd) return (int)p.size() - 1;
			while (cp < (int)p.size() && p[cp].l == cd)
			{
				have.insert(make_pair(p[cp].r, p[cp].id));
				cp++;
			}
		}
	}
	return p.size();
}

void Solve()
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (psg[i].t == 1)
		{
			p.push_back(psg[i]);
		}
	}
	sort(p.begin(), p.end());
	if (CountAns() != p.size())
	{
		printf("0\n");
		return;
	}
	for (i = 0; i < n; i++)
	{
		if (psg[i].t == 1) continue;
		p.push_back(psg[i]);
		int cp = ((int)p.size()) - 2;
		while (cp >= 0 && p[cp].l > psg[i].l) cp--;
		int j;
		for (j = p.size() - 1; j > cp + 1; j--)
		{
			p[j] = p[j - 1];
		}
		p[cp + 1] = psg[i];
		if (CountAns() != p.size())
		{
			for (j = cp + 1; j < p.size() - 1; j++) p[j] = p[j + 1];
			p.pop_back();
		}
	}
	memset(result, 0, sizeof(result));
	printf("%d\n", CountAns());
	for (i = 0; i < n; i++) printf("%d ", result[i]);
	printf("\n");
}

int main()
{
	freopen("planes.in", "rt", stdin);
	freopen("planes.out", "wt", stdout);
	Load();
	Solve();
	return 0;
}
