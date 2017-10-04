#include <cstdio>
#include <vector>
#include <set>

using namespace std;

const int lg = 200005;

int n, m, x, y, q, nrs, ind, p1, p2, i, j, euler[lg][2], init[lg], s, prc, left, right, bag[lg], tata[lg], test;
vector<int> stie[lg], v[lg], w[lg];
bool fst[lg];

void df(int nod){
	for (int i = 0; i < (int)v[nod].size(); i ++){
		tata[ v[nod][i] ] = nod;
		df(v[nod][i]);
	}
}
void mark(int nod){
	bag[nod] = test;
	
	for (int i = 0; i < (int)v[nod].size(); i ++)
		mark(v[nod][i]);
}
int caut(int nod){
	for (int i = 0; i < (int)w[nod].size(); i ++)
		if (bag[ w[nod][i] ] == test)
			return 1;
	
	for (int i = 0; i < (int)v[nod].size(); i ++)
		if (caut(v[nod][i]) == 1)
			return 1;
			
	return 0;
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
	
	for (test = 1; test <= q; test ++){
		scanf("%d %d %d", &s, &x, &y);
		
		if (s == 2){
			w[x].push_back(y);
		}
		else{
			int gs = 0;
			mark(y);
			
			gs = caut(x);
	
			
			if (!gs)
				for (x = tata[x]; x > 0 && gs == 0; x = tata[x])
					for (i = 0; i < (int)w[x].size(); i ++)
						if (bag[ w[x][i] ] == test){
							gs = 1;
							break;
						}
						
			if (!gs)
				printf("NO\n");
			else
				printf("YES\n");
		}
	}

	return 0;
}


