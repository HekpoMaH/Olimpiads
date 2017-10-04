#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX 64
#define INF 0xDEAD
using namespace std;
FILE *in; FILE *out;

struct Point
{
	int row, col, moves;
	bool operator < (const Point& r) const
		{return row != r.row ? row < r.row : col < r.col;}
	Point(int row_ = 0, int col_ = 0) {row = row_; col = col_; moves = 0;}
};

int n, m;
char a[MAX][MAX];
Point Elly, Exit;
vector <Point> princes;
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

int findDistance(Point start, Point finish)
{
	Point cur, next;
	queue <Point> q;
	int vis[MAX][MAX];
	memset(vis, 0, sizeof(vis));

	q.push(start);
	vis[start.row][start.col] = 1;

	while (!q.empty())
	{
		cur = q.front(); q.pop();
		if (cur.row == finish.row && cur.col == finish.col) return cur.moves;

		next.moves = cur.moves + 1;
		for (int i = 0; i < 4; i++)
		{
			next.row = (cur.row + dir[i][0] + n) % n;
			next.col = (cur.col + dir[i][1] + m) % m;
			if (a[next.row][next.col] == '#') continue;

			if (!vis[next.row][next.col])
			{
				q.push(next);
				vis[next.row][next.col] = 1;
			}
		}
	}
	return INF;
}

int main(void)
{
	in = stdin; out = stdout;
//	in = fopen("castle.in", "rt"); out = fopen("castle.out", "wt");

	fscanf(in, "%d %d", &n, &m);
	for (int i = 0; i < n; i++) fscanf(in, "%s", a[i]);

	for (int i = 0; i < n; i++)
	{
		for (int c = 0; c < m; c++)
		{
			if (a[i][c] == 'E') {Elly.row = i; Elly.col = c; a[i][c] = '.';}
			if (a[i][c] == 'X') {Exit.row = i; Exit.col = c; a[i][c] = '.';}
			if (a[i][c] == 'P') {princes.push_back(Point(i, c)); a[i][c] = '.';}
		}
	}

	int ans = INF;
	if (princes.empty()) // No princes to rescue
		ans = findDistance(Elly, Exit);
	else
	{
		sort(princes.begin(), princes.end());
		do
		{
			int cur = 0;
			cur += findDistance(Elly, princes[0]);
			for (int i = 1; i < (int)princes.size(); i++)
				cur += findDistance(princes[i - 1], princes[i]);
			cur += findDistance(princes.back(), Exit);
			ans = min(ans, cur);
		}
		while (next_permutation(princes.begin(), princes.end()));
	}
	fprintf(out, "%d\n", ans < INF ? ans : -1);
	return 0;
}
