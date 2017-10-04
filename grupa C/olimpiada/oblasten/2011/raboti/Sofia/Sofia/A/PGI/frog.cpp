#include <cstdio>
#include <vector>

#define MAX(a, b) (((a) < (b)) ? (b) : (a))
#define ABS(a) ((a) < 0 ? (-(a)) : (a))

struct point
{
	int x, y;
	point() {x = y = 0;};
	point(int _x, int _y) {x = _x; y = _y;};
};

/*struct path
{
	int last_last, last_point, current_point, dist, num_visited;
	int visited[12];
	path() {last_last = last_point = current_point = -1; num_visited = dist = 0; for (int i = 0; i < 12; i++) {visited[i] = 0;}};
};*/

struct square
{
	int d, centre, hit_count, visited[12];
	square() {d = hit_count = 0; for (int i = 0; i < 12; i++) {visited[i] = 0;}};
};

point points[13];
int dist[13][13];
int visited[12];
//int dist0[12];

int main()
{
	int n, half_n, sc_n, sc_x, sc_y;
	scanf("%d", &n);
	half_n = n;
	n = sc_n = 2*n;

	for (int i = 0, ni = 0; i < sc_n; i++)
	{
		scanf("%d %d", &sc_x, &sc_y);
		if ((sc_x + sc_y) % 2 == 1)
		{
			//printf("aaa\n");
			--n;
			continue;
		}

		points[ni].x = sc_x;
		points[ni++].y = sc_y;
	}

	points[n] = point(0, 0);

	/*for (int i = 0; i < n; i++)
	{
		dist0[i] = MAX(ABS(points[i].x), ABS(points[i].y));
	}*/
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			dist[i][j] = MAX(ABS(points[i].x - points[j].x), ABS(points[i].y - points[j].y));
		}
	}

	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("dist[(%d, %d), (%d, %d)] = %d\n", points[i].x, points[i].y, points[j].x, points[j].y, dist[i][j]);
		}
	}*/

	/*std::vector<path> paths;
	int size;

	path start;
	start.current_point = n;
	start.dist = 0;
	start.num_visited = 0;

	while (true)
	{

	}*/

	std::vector<square> sq;
	std::vector<int> visit;

	int size, d = 0;

	square start;
	start.centre = n;
	sq.push_back(start);

	while (true)
	{
		d++;
		size = sq.size();

		for (int i = 0; i < size; i++)
		{
			sq[i].d++;
			for (int j = 0; j < n; j++)
			{
				if (dist[j][sq[i].centre] == sq[i].d)
				{
					if (sq[i].hit_count+1 == half_n && !sq[i].visited[j])
					{
						printf("%d\n", d);
						return 0;
					}
					start = square();
					start.centre = j;
					start.hit_count = sq[i].hit_count;
					for (int a = 0; a < 12; a++) start.visited[a] = sq[i].visited[a];
					start.visited[j] = 1;
					if (!sq[i].visited[j])
					{
						//printf("%d hits %d\n", sq[i].centre, j);
						start.hit_count++;
					}

					sq.push_back(start);
				}
			}
		}

		//for (int i = 0; i < visit.size(); i++)
		//	visited[visit[i]] = 1;

		//visit.clear();
	}



	return 0;
}
