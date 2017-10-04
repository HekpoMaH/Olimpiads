/*
ID: espr1t
LANG: C++
TASK: race
AUTH: Alexander Georgiev
COMP: Spring National Contest
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#define MAX_TEAMS 512
#define MAX_TASKS 512
#define MAX_REQ 16
#define INF 999666333

using namespace std;
FILE *in; FILE *out;

struct Point {int x, y, t;};

Point final; int minTasks;
Point teams[MAX_TEAMS]; int numTeams;
Point tasks[MAX_TASKS]; int numTasks;
int ans[MAX_TASKS][MAX_REQ], vis[MAX_TASKS][MAX_REQ];

int calcTime(Point a, Point b) {return abs(a.x - b.x) + abs(a.y - b.y) + b.t;}

void eval()
{
	memset(vis, 0, sizeof(vis));
	memset(ans, 111, sizeof(ans));
	
	for (int i = 0; i < numTasks; i++)
		ans[i][minTasks - 1] = calcTime(final, tasks[i]);

	while (1)
	{
		int best = INF, who = -1, rem = -1;
		for (int i = 0; i < numTasks; i++)
			for (int c = 1; c < minTasks; c++)
				if (!vis[i][c] && best > ans[i][c])
					{best = ans[i][c]; who = i; rem = c;}
		
		if (best >= INF) break;
		vis[who][rem] = 1;
		for (int i = 0; i < numTasks; i++) if (i != who)
			if (best + calcTime(tasks[who], tasks[i]) < ans[i][rem - 1])
				ans[i][rem - 1] = best + calcTime(tasks[who], tasks[i]);
	}
}

int main(void)
{
	in = stdin; out = stdout;
//	in = fopen("Race.in", "rt"); out = fopen("Race.out", "wt");
	
	fscanf(in, "%d %d", &numTeams, &minTasks);
	for (int i = 0; i < numTeams; i++)
	{
		teams[i].t = 0;
		fscanf(in, "%d %d", &teams[i].x, &teams[i].y);
	}
	
	fscanf(in, "%d", &numTasks);
	for (int i = 0; i < numTasks; i++)
		fscanf(in, "%d %d %d", &tasks[i].x, &tasks[i].y, &tasks[i].t);
	
	fscanf(in, "%d %d", &final.x, &final.y);
	
	eval();
	for (int i = 0; i < numTeams; i++)
	{
		int best = INF;
		for (int c = 0; c < numTasks; c++)
			best = min(best, ans[c][0] + calcTime(tasks[c], teams[i]));
		fprintf(out, "%d\n", best);
	}
	return 0;
}
