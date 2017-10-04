/*
ID: espr1t
TASK: Garbage
KEYWORDS: Medium, Dynamic Programming
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 100;
const int DIM = 5050;
const int INF = 32000;

int n, m;
int a[MAX][MAX];
short rows[MAX][MAX][MAX];
short cols[MAX][MAX][MAX];
short indx[MAX][MAX];
short dyn[DIM][DIM];

short recurse(int srow, int erow, int scol, int ecol) {
    if (erow < srow || ecol < scol)
        return 0;
    int idx1 = indx[srow][erow], idx2 = indx[scol][ecol];
    if (dyn[idx1][idx2] != -1)
        return dyn[idx1][idx2];
    
    int ans = INF;
    ans = min(ans, recurse(srow + 1, erow, scol, ecol) + rows[srow][scol][ecol]); // Top row
    ans = min(ans, recurse(srow, erow - 1, scol, ecol) + rows[erow][scol][ecol]); // Bottom row
    ans = min(ans, recurse(srow, erow, scol + 1, ecol) + cols[scol][srow][erow]); // Left column
    ans = min(ans, recurse(srow, erow, scol, ecol - 1) + cols[ecol][srow][erow]); // Right column
    return dyn[idx1][idx2] = (short)ans;
}

void precalc() {
    // Indices
    int nxt = 0;
    for (int start = 0; start < MAX; start++)
        for (int end = start; end < MAX; end++)
            indx[start][end] = nxt++;
    
    // Rows
    for (int row = 0; row < n; row++) {
        for (int scol = 0; scol < m; scol++) {
            rows[row][scol][scol] = a[row][scol];
            for (int ecol = scol + 1; ecol < m; ecol++)
                rows[row][scol][ecol] = max((short)a[row][ecol], rows[row][scol][ecol - 1]);
        }
    }

    // Columns
    for (int col = 0; col < m; col++) {
        for (int srow = 0; srow < n; srow++) {
            cols[col][srow][srow] = a[srow][col];
            for (int erow = srow + 1; erow < n; erow++)
                cols[col][srow][erow] = max((short)a[erow][col], cols[col][srow][erow - 1]);
        }
    }
}

int main(void) {
    FILE* in = stdin; FILE* out = stdout;
//    in = fopen("Garbage.in", "rt"); out = fopen("Garbage.out", "wt");
    
    fscanf(in, "%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int c = 0; c < m; c++)
            fscanf(in, "%d", &a[i][c]);
    
    precalc();
    memset(dyn, -1, sizeof(dyn));
    fprintf(out, "%d\n", (int)recurse(0, n - 1, 0, m - 1));
    return 0;
}
