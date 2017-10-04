#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

#define lint long long
#define pi pair< pair<lint, lint>, pair<int, int> >
#define x first
#define y second

const int lg = 200005;

int n, m, i, p, x, y, father[lg], h[lg], s1, s2, much;
pi v[lg], d[lg];
pair<long long, long long> answer[lg], w[lg];

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

bool cmp(pi a, pi b){
	if (a.x.x != b.x.x)
		return a.x.x < b.x.x;
	return a.x.y > b.x.y;
}
bool cmp2(pair<long long, long long> a, pair<long long, long long> b){
	if (a.x != b.x)
		return a.x < b.x;
	return a.y > b.y;
}

void terminate(string mesaj, int punctaj){
	fprintf(stderr, "%s", mesaj.c_str());
	fprintf(stdout, "%d", punctaj);

	exit(0);
}

int main()
{
	FILE *f = fopen("lazy.in", "rt");
	FILE *g = fopen("lazy.out", "rt");

	if ( f == NULL )
		terminate("Missing input file!", 0);

	if ( g == NULL )
		terminate("Missing output file!", 0);

	fscanf(f, "%d%d", &n, &m);
	for (i = 1; i <= m; i ++){
		fscanf(f, "%d%d%lld%lld", &v[i].y.x, &v[i].y.y, &v[i].x.x, &v[i].x.y);

		d[i] = v[i];
	}

	sort(v + 1, v + m + 1, cmp);

	for (i = 1, p = 1; p < n && i <= m; i ++){
		x = find(v[i].y.x);
		y = find(v[i].y.y);

		if (x != y){
			w[p].x = v[i].x.x, w[p].y = v[i].x.y;
		
			unite(x, y);
			p ++;
		}
	}

	memset(h, 0, sizeof(h));
	memset(father, 0, sizeof(father));

	for (i = 1; i < n; i ++){
		if (fscanf(g, "%d", &much) != 1)
			terminate("Incorrect!3\n", 0);

		x = find(d[much].y.x), y = find(d[much].y.y);


		if (x == y){
			terminate("Incorrect!2\n", 0);
		}

		unite(x, y);

		answer[i].x = d[much].x.x;
		answer[i].y = d[much].x.y;
	}

	sort(answer + 1, answer + n, cmp2);
	
	for (i = 1; i < n; i ++)
		if (answer[i].x != w[i].x || answer[i].y != w[i].y)
			printf("at pos i=%d real %lld,%lld your %lld,%lld \n",i,w[i].x,w[i].y,answer[i].x,answer[i].y),terminate("Incorrect!1\n", 0);

	terminate("Correct!\n", 10);
}

