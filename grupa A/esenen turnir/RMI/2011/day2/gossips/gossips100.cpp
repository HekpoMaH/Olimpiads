#include <cstdio>
#include <vector>
#include <set>

using namespace std;

const int lg = 100005;

int n, m, x, y, q, nrs, ind, p1, p2, i, j, euler[lg][2], init[lg], s, prc, left, right;
vector<int> stie[lg], v[lg];
set<int> arb[560000], tot[560000];
bool fst[lg];

void df(int nod){
	prc ++;
	euler[nod][0] = prc;

	for (int i = 0; i < (int)v[nod].size(); i ++)
		df(v[nod][i]);

	euler[nod][1] = prc;
}
void build(int st, int dr, int poz){
	if (st == dr){
		init[st] = poz;
		return ;
	}

	int mij = (st + dr) / 2;

	build(st, mij, 2 * poz); build(mij + 1, dr, 2 * poz + 1);
}
void insert(int st, int dr, int poz){
	if (p1 > dr || p2 < st)
		return ;

	arb[poz].insert(left);

	if (p1 <= st && dr <= p2){
		tot[poz].insert(left);

		return ;
	}

	int mij = (st + dr) / 2;
	insert(st, mij, 2 * poz); insert(mij + 1, dr, 2 * poz + 1);
}

bool find(int st, int dr, int poz){
	if (p1 <= st && dr <= p2){
		set<int> :: iterator it = arb[poz].lower_bound(left);

		if (it == arb[poz].end() || *it > right)
			return 0;
		return 1;
	}

	if (p1 > dr || p2 < st)
		return 0;

	set<int> :: iterator it = tot[poz].lower_bound(left);
	if (it != tot[poz].end() && *it <= right)
		return 1;


	int mij = (st + dr) / 2;
	return max(find(st, mij, 2 * poz), find(mij + 1, dr, 2 * poz + 1));
}

int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for (i = 1; i <= m; i ++){
		scanf("%d%d", &x, &y);

		v[x].push_back(y);
		fst[y] = 1;
	}
	ind = n + 1;
	for (i = 1; i < ind; i ++)
		if (!fst[i])
			v[ind].push_back(i);
	df(ind);

	for (i = 1; i <= q; i ++){
		scanf("%d%d%d", &s, &x, &y);

		p1 = euler[x][0];
		p2 = euler[x][1];

		left = euler[y][0];
		right = euler[y][1];


		if (s == 2)
			insert(1, ind, 1);
		else
			if (find(1, ind, 1) == 1)
				printf("YES\n");
			else
				printf("NO\n");
	}

	return 0;
}


