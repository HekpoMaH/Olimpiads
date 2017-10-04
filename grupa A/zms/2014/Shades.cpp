/*
ID: espr1t
TASK: Shades
KEYWORDS: Medium, Logical, Graph
IDEA:
    It's relatively easy to see that if the parity of (row + column) of the
    starting and ending cells is the same, then the path will have an odd number
    of visited cells, in which case there can never be a solution.
    
    If the parity is different, there are still cases when there might not be a
    solution (for example completely white or completely black boards).
   
    First we will try to find a path, that has at most +1/-1 balance at all
    times. This will find a path in a chessboard, for example, but also handle
    not so obvious cases like "WBBW".
   
    In all other cases (i.e. if the path needs to have a balance greater than
    or equal to +2/-2 at some point) we can show that in order for it to be
    zero in the end, there must be a patch of two consecutive white cells and
    also one of two consecutive black ones. But then we can always solve it by
    going from the start cell to the white patch, making several steps there
    (effectively increasing the number of white cells with as much as needed),
    then going to the black patch, making several steps there as well
    (effectively increasing the number of black cells with as much as needed),
    and in the end going to the target cell.
*/

#include <cstdio>
#include <cstring>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;
FILE* in = stdin; FILE* out = stdout;

const int MAX = 512;
const int INF = 1000000001;


struct State {
    int row, col, balance;
    State(int row_ = 0, int col_ = 0, int balance_ = 0) :
        row(row_), col(col_), balance(balance_) {};
};

int n, m;
char a[MAX][MAX];
int r1, c1, r2, c2;
int vis[MAX][MAX][3], pre[MAX][MAX][3];
int balanceBlack[MAX][MAX], prevBlack[MAX][MAX], blackRow, blackCol;
int balanceWhite[MAX][MAX], prevWhite[MAX][MAX], whiteRow, whiteCol;

char name[4] = { 'U', 'R', 'D', 'L' };
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };


bool hasAlternating() {
    queue <State> q;
    memset(vis, 0, sizeof(vis));

    State nxt = State(r1, c1, 1 + (a[r1][c1] == 'W' ? -1 : 1));
    q.push(nxt);
    pre[nxt.row][nxt.col][nxt.balance] = -1;
    vis[nxt.row][nxt.col][nxt.balance] = true;
   
    while (!q.empty()) {
        State cur = q.front(); q.pop();
        if (cur.row == r2 && cur.col == c2 && cur.balance == 1)
            break;
        
        for (int i = 0; i < 4; i++) {
            nxt.row = cur.row + dir[i][0]; if (nxt.row < 0 || nxt.row >= n) continue;
            nxt.col = cur.col + dir[i][1]; if (nxt.col < 0 || nxt.col >= m) continue;
            nxt.balance = cur.balance + (a[nxt.row][nxt.col] == 'W' ? -1 : +1);
            if (nxt.balance < 0 || nxt.balance >= 3)
                continue;

            if (!vis[nxt.row][nxt.col][nxt.balance]) {
                q.push(nxt);
                pre[nxt.row][nxt.col][nxt.balance] = i;
                vis[nxt.row][nxt.col][nxt.balance] = true;
            }
        }
    }
   
    if (vis[r2][c2][1]) {
        // Found a path!
        string path;
        State cur = State(r2, c2, 1);
        while (pre[cur.row][cur.col][cur.balance] != -1) {
            int d = pre[cur.row][cur.col][cur.balance];
            path += name[d];
            cur.balance -= (a[cur.row][cur.col] == 'W' ? -1 : +1);
            cur.row -= dir[d][0], cur.col -= dir[d][1];
        }
        reverse(path.begin(), path.end());
        fprintf(out, "%d %s\n", (int)path.size() + 1, path.c_str());
        return true;
    }
    return false;
}


void eval() {
    // Check the parity
    if ((abs(r1 - r2) + abs(c1 - c2)) % 2 == 0) {
        fprintf(out, "-1\n");
        return;
    }
   
    // Check for path with at most +1/-1 balance at any time.
    if (hasAlternating())
        return;
   
    // Check for WW and BB patches
    if (blackRow < 0 || whiteRow < 0) {
        fprintf(out, "-1\n");
        return;
    }
    
    // Now we are sure there is an answer, going through the
    // following path: start cell -> black patch -> white patch -> end cell

    int balance = balanceBlack[r1][c1] + balanceWhite[blackRow][blackCol] +
        balanceWhite[r2][c2];
    string path = "";
    int row = r1, col = c1;
    // Go from (r1, c1) to the black patch
    while (row != blackRow || col != blackCol) {
        int d = prevBlack[row][col];
        path += name[(d + 2) % 4];
        row -= dir[d][0], col -= dir[d][1];
    }
    // Step on the black patch for a while
    for (int i = 0; i < 4; i++) {
        int nrow = row + dir[i][0]; if (nrow < 0 || nrow >= n) continue;
        int ncol = col + dir[i][1]; if (ncol < 0 || ncol >= m) continue;
        if (a[nrow][ncol] == 'B') {
            while (balance < 0) {
                path += name[i]; balance++;
                path += name[(i + 2) % 4]; balance++;
            }
            break;
        }
    }
    // Go from the black patch to the white patch
    while (row != whiteRow || col != whiteCol) {
        int d = prevWhite[row][col];
        path += name[(d + 2) % 4];
        row -= dir[d][0], col -= dir[d][1];
    }
    // Step on the white patch for a while
    for (int i = 0; i < 4; i++) {
        int nrow = row + dir[i][0]; if (nrow < 0 || nrow >= n) continue;
        int ncol = col + dir[i][1]; if (ncol < 0 || ncol >= m) continue;
        if (a[nrow][ncol] == 'W') {
            while (balance > 0) {
                path += name[i]; balance--;
                path += name[(i + 2) % 4]; balance--;
            }
            break;
        }
    }
    // Go from the white patch to (r2, c2)
    string add;
    row = r2, col = c2;
    while (row != whiteRow || col != whiteCol) {
        int d = prevWhite[row][col];
        add += name[d];
        row -= dir[d][0], col -= dir[d][1];
    }
    reverse(add.begin(), add.end());
    path += add;

    fprintf(out, "%d %s\n", (int)path.size() + 1, path.c_str());
}


void bfs(int balance[MAX][MAX], int prev[MAX][MAX], int srow, int scol) {
    queue <State> q;
    State nxt = State(srow, scol, a[srow][scol] == 'W' ? -1 : 1);
    q.push(nxt);
    prev[nxt.row][nxt.col] = -1;
    balance[nxt.row][nxt.col] = nxt.balance;
    int cnt = 0;
    while (!q.empty()) {
        State cur = q.front(); q.pop();
        cnt++;
        for (int i = 0; i < 4; i++) {
            nxt.row = cur.row + dir[i][0]; if (nxt.row < 0 || nxt.row >= n) continue;
            nxt.col = cur.col + dir[i][1]; if (nxt.col < 0 || nxt.col >= m) continue;
            nxt.balance = cur.balance + (a[nxt.row][nxt.col] == 'W' ? -1 : 1);
            if (balance[nxt.row][nxt.col] >= INF) {
                q.push(nxt);
                prev[nxt.row][nxt.col] = i;
                balance[nxt.row][nxt.col] = nxt.balance;
            }
        }
    }
}


void init() {
    blackRow = blackCol = -1;
    whiteRow = whiteCol = -1;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            balanceBlack[row][col] = INF, prevBlack[row][col] = -1;
            balanceWhite[row][col] = INF, prevWhite[row][col] = -1;
        }
    }
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            for (int i = 0; i < 4; i++) {
                int nrow = row + dir[i][0]; if (nrow < 0 || nrow >= n) continue;
                int ncol = col + dir[i][1]; if (ncol < 0 || ncol >= m) continue;
                if (blackRow < 0 && a[row][col] == 'B' && a[nrow][ncol] == 'B') {
                    blackRow = row, blackCol = col;
                    bfs(balanceBlack, prevBlack, blackRow, blackCol);
                }
                if (whiteRow < 0 && a[row][col] == 'W' && a[nrow][ncol] == 'W') {
                    whiteRow = row, whiteCol = col;
                    bfs(balanceWhite, prevWhite, whiteRow, whiteCol);
                }
            }
        }
    }
}


int main(void) {
//    in = fopen("Shades.in", "rt"); // out = fopen("Shades.out", "wt");

    fscanf(in, "%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        fscanf(in, "%s", a[i]);
    init();
   
    int numQueries;
    fscanf(in, "%d", &numQueries);
    for (int q = 0; q < numQueries; q++) {
        fscanf(in, "%d %d %d %d", &r1, &c1, &r2, &c2);
        r1--; c1--; r2--; c2--;
        eval();
    }
    return 0;
}
