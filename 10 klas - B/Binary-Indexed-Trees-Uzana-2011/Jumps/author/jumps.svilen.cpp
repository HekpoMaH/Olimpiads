// Reshenie na jumps ot Svilen Marchev
// slojnost po vreme O(NlogN)
// slojnost po pamet O(N)

#include <cstdio>
#include <algorithm>

using namespace std;

#define MN		(1 << 20)

struct Point {
	int x,y;

	bool operator==(const Point& p) const {
		return (x==p.x && y==p.y);
	}
};

bool sortByX(const Point& p1, const Point& p2)
{
	if (p1.x==p2.x) return p1.y<p2.y;
	return p1.x<p2.x;
}
bool sortByY(const Point& p1, const Point& p2)
{
	if (p1.y==p2.y) return p1.x<p2.x;
	return p1.y<p2.y;
}

Point P[MN];
int N;

// implementaciq na binary indexed tree (BIT)
int t[MN];

int query(int i)
{
	int r=0;
	for (; i>0; i-=i&(-i))
		r = max(r,t[i]);
	return r;
}

void update(int i, int x)
{
	for (; i<=N; i+=i&(-i))
		t[i] = max(t[i], x);
}

int main()
{
	int i,q;

	scanf("%d",&N);
	for (i=0; i<N; ++i)
		scanf("%d%d",&P[i].x,&P[i].y);

	// sortirame po Y, za da mojem da premahnem
	// dublirashtite se tochki i da vyvedem novi
	// Y-koordinati na tochkite (interesuva ni
	// samo tqhnata relativna naredba, ne konkretnite
	// im stoinosti)
	sort(P,P+N,sortByY);
	N = unique(P,P+N)-P;
	for (i=0; i<N; ++i)
		P[i].y = i+1;

	// sortirame po X, obhojdame gi i gi pribavqme
	// v dyrvoto
	sort(P,P+N,sortByX);
	memset(t,0,sizeof t);

	for (i=0; i<N; ++i) {
		q = query(P[i].y);
		update(P[i].y, q+1);
	}

	printf("%d\n", query(N));

	return 0;
}
