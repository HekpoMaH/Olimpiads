#include <cstdio>
#include <algorithm>

using namespace std;

#define lint long long
#define pi pair< pair<lint, lint>, pair< pair<int, int> , int> >
#define x first
#define y second

const int lg = 200005;

int n, m, i, p, x, y, father[lg], h[lg], s1, s2;
pi v[lg];

int find(int x){
	int found, z;

	for (z = x; father[z]; z = father[z]);
	found = z;

	for (; father[x]; ){
		z = father[x];
		father[x] = found;
		x = z;
	}

	return found;
}
void unite(int x, int y){
	if (h[x] < h[y]){
		father[x] = y;
	}
	else{
		father[y] = x;

		if (h[x] == h[y])
			h[x] ++;
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for (i = 1; i <= m; i ++){
		scanf("%d%d%lld%lld", &v[i].y.x.x, &v[i].y.x.y, &v[i].x.x, &v[i].x.y);

		v[i].x.y = -v[i].x.y;
		v[i].y.y = i;
	}

	sort(v + 1, v + m + 1);

	for (i = 1, p = 1; p < n && i <= m; i ++){
		x = find(v[i].y.x.x);
		y = find(v[i].y.x.y);

		if (x != y){
			printf("%d\n", v[i].y.y);

			unite(x, y);
			p ++;
		}
	}

	return 0;
}


