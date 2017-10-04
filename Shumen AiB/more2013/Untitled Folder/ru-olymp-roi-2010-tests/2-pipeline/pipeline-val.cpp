#include "testlib.h"
using namespace std;

const int MAXN = 2000;
const int MAXK = 40;

bool con[MAXN][MAXN];
bool have_edge[MAXN];

int main()
{
    registerValidation();

    int n = inf.readInt(2, MAXN);
	inf.readSpace();
	int m = inf.readInt(1, n*(n-1) / 2);
	inf.readSpace();
	int k = inf.readInt(1, min(n, MAXK));
	inf.readEoln();

	for (int i=0; i<m; i++){
		int x = inf.readInt(1, n) - 1;
		inf.readSpace();
		int y = inf.readInt(1, n) - 1;
		inf.readEoln();
		ensuref(x != y, "There is a loop in edges!");
		ensuref(!con[x][y], "Same edge listed twice!");
		con[x][y] = true;
		con[y][x] = true;
		have_edge[x] = true;
		have_edge[y] = true;
	}

	for (int i=0; i<n; i++){
		ensuref(have_edge[i], "There is an isolated vertex!");
	}

    inf.readEof();
    return 0;
}
