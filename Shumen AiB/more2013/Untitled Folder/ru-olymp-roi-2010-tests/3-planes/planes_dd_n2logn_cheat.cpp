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

vector<Passenger> phave, padd;
	
bool CheckAns(int la, int ra)
{
	p.resize(phave.size() + (ra - la + 1));
	int cp = 0;
	int cph, cpa;
	cph = 0;
	cpa = la;
	while (cph < phave.size() && cpa <= ra)
	{
		if (phave[cph] < padd[cpa]) p[cp++] = phave[cph++];
		else p[cp++] = padd[cpa++];
	}
	while (cph < phave.size()) p[cp++] = phave[cph++];
	while (cpa <= ra) p[cp++] = padd[cpa++];
	return CountAns() == p.size();
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
	phave = p;
	for (i = 0; i < n; i++) 
	{
		if (psg[i].t == 1) continue;
		padd.push_back(psg[i]);
	}
	sort(padd.begin(), padd.end());
	int cpadd = 0;
	while (cpadd < padd.size())
	{
		int cpl = cpadd;
		int cpr = cpadd;
		int cmv = 1;
		int gr = cpadd - 1;
		while (CheckAns(cpl, cpr))
		{
			gr = cpr;
			if (cpr == padd.size() - 1) { break; }
			cpr += cmv;
			if (cpr >= padd.size()) cpr = padd.size() - 1;
			cmv *= 2;
		}
		cmv /= 4;
		if (cmv == 0) cmv = 1;
		while (cmv > 0)
		{
			cpr = gr + cmv;
			if (cpr >= padd.size()) cpr = padd.size() - 1;
			if (CheckAns(cpl, cpr)) gr = cpr;
			else cmv /= 2;
			if (gr == padd.size() - 1) break;
		}
		for (i = cpl; i <= gr; i++) phave.push_back(padd[i]);
		sort(phave.begin(), phave.end());
		cpadd = gr + 2;
	}
	memset(result, 0, sizeof(result));
	p = phave;
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
