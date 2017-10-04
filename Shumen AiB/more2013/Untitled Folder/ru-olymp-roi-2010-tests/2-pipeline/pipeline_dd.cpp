#include <iostream>
#include <fstream>
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>
#include <map>

using namespace std;

const int MAXM = 100000;
const int MAXN = 2000;

class Edge
{
public:
	int be, en;
};

bool operator<(const Edge &a, const Edge &b)
{
	return a.be < b.be;
}

int n, m, k;
Edge edg[2 * MAXM];
int first[MAXN];
int next[2 * MAXM];
int ne;
int ebe[MAXN];
int een[MAXN];

void AddEdge(int v1, int v2)
{
	edg[ne].be = v1;
	edg[ne].en = v2;
	next[ne] = first[v1];
	first[v1] = ne;
	ne++;
}

void Load()
{
	ne = 0;
	scanf("%d%d%d", &n, &m, &k);
	int i;
	for (i = 0; i < m; i++)
	{
		int p, q;
		scanf("%d%d", &p, &q);
		p--;
		q--;
		AddEdge(p, q);
		AddEdge(q, p);
	}
	sort(edg, edg + ne);
	memset(first, 0xFF, sizeof(first));
	for (i = 0; i < ne; i++)
	{
		next[i] = first[edg[i].be];
		first[edg[i].be] = i;
	}
	memset(ebe, 0xFF, sizeof(ebe));
	memset(een, 0xFF, sizeof(een));
	for (i = 0; i < ne; i++) if (ebe[edg[i].be] == -1) ebe[edg[i].be] = i;
	for (i = 0; i < n; i++)
	{
		if (ebe[i] == -1) continue;
		een[i] = ebe[i];
		while (een[i] < ne && edg[een[i]].be == i) een[i]++;
	}
/*	cerr << "Edges:\n";
	for (i = 0; i < ne; i++)
	{
		cerr << edg[i].be << " " << edg[i].en << "\n";
	}
	cerr << "Ebe: ";
	for (i = 0; i < n; i++) cerr << ebe[i] << " ";
	cerr << "\n";
	cerr << "Een: ";
	for (i = 0; i < n; i++) cerr << een[i] << " ";
	cerr << "\n";*/
}

class Vertex
{
public:
	int id;
	Vertex(int a) { id = a; }
};

int pwr[MAXN];

bool operator<(const Vertex &a, const Vertex &b)
{
	if (pwr[a.id] > pwr[b.id]) return true;
	if (pwr[a.id] < pwr[b.id]) return false;
	return a.id < b.id;
}

int ans[MAXN];
int colored;

void MarkEdges(int cv, int dpt)
{
	int i;
	ans[cv] = 1;
	for (i = ebe[cv]; i < een[cv]; i++)
	{
		if (ans[edg[i].en] != 0) continue;
		colored += 2;
		pwr[edg[i].en]--;
		pwr[edg[i].be]--;
	}
}

void UnMarkEdges(int cv, int dpt)
{
	int i;
	ans[cv] = 0;
	for (i = ebe[cv]; i < een[cv]; i++)
	{
		if (ans[edg[i].en] != 0) continue;
		colored -= 2;
		pwr[edg[i].en]++;
		pwr[edg[i].be]++;
	}
}

bool Find(int dpt)
{
	if (colored == ne) return true;
	if (dpt == k) return false;
	int i;
	int cv = -1;
	for (i = 0; i < n; i++) 
	{
		if (pwr[i] > 0)
		{
			if (cv == -1 || pwr[i] > pwr[cv]) cv = i;
		}
	}
	if ((ne - colored) / 2 > (k - dpt) * pwr[cv]) return false;
	// take all neighbours of this
	if (pwr[cv] + dpt <= k)
	{
		vector<int> cvs;
		for (i = ebe[cv]; i < een[cv]; i++)
		{
			if (ans[edg[i].en] != 0) continue;
			//if (was[i] != 0) continue;
			cvs.push_back(edg[i].en);
		}
		for (i = 0; i < cvs.size(); i++) MarkEdges(cvs[i], dpt);
		if (Find(dpt + cvs.size())) return true;
		for (i = 0; i < cvs.size(); i++) UnMarkEdges(cvs[i], dpt);
	}
	// take this vertex
	MarkEdges(cv, dpt);
	if (Find(dpt + 1)) return true;
	UnMarkEdges(cv, dpt);
	return false;
}

void Solve()
{
	int i;
	memset(pwr, 0, sizeof(pwr));
	for (i = 0; i < ne; i++) pwr[edg[i].be]++;
	//memset(was, 0, sizeof(was));
	memset(ans, 0, sizeof(ans));
	colored = 0;
	if (Find(0))
	{
		vector<int> p;
		for (i = 0; i < n; i++)
		{
			if (ans[i] == 1) p.push_back(i);
		}
		for (i = 0; i < n; i++)
		{
			if (p.size() == k) break;
			if (ans[i] == 0) p.push_back(i);
		}
		printf("Yes\n");
		for (i = 0; i < k; i++) printf("%d ", p[i] + 1);
		printf("\n");
	}
	else
	{
		printf("No\n");
	}
}

int main()
{
	freopen("pipeline.in", "rt", stdin);
	freopen("pipeline.out", "wt", stdout);
	Load();
	Solve();
	return 0;
}