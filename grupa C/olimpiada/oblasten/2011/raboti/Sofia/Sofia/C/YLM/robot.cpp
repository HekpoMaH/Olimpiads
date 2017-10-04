#include <iostream>
#include <queue>
using namespace std;
bool used [10000];
int D [10000];
//int sum [10000];
int table [100][100];
int susedi [10000][10000];
int br[10000];
int path = 0;
long long sums = 0;
int m, n, r, k;
void dfs (int vruh)
{
     if(path == k && !used[vruh])  { sums += vruh; used[vruh] = true; return; }
     if(path == k) return;
     path ++;
     for(int i = 0; i < br[vruh]; i ++) { dfs(susedi[vruh][i]); }
     path --;
     return;
}
int main ()
{
    int cnt = 1;
    cin >> m >> n >> r >> k;
    for(int i = 0; i < m; i ++)
    for(int j = 0; j < n; j ++) { table [i][j] = cnt; cnt ++; }
    for(int i = 0; i < m - 1; i ++)
    {
        for(int j = 0; j < n - 1; j ++)
        {
                susedi[table[i][j]][br[table[i][j]]] = table [i][j+1];
                br[table[i][j]]++;
                susedi[table[i][j+1]][br[table[i][j+1]]] = table [i][j];
                br[table[i][j+1]]++;
                susedi[table[i+1][j]][br[table[i+1][j]]] = table [i][j];
                br[table[i+1][j]]++;
                susedi[table[i][j]][br[table[i][j]]] = table [i+1][j];
                br[table[i][j]]++;

        }
    }
    for(int i = 0; i < m - 1; i ++)
    {
        susedi [table[i][n-1]][br[table[i][n-1]]] = table[i+1][n-1];
        br[table[i][n-1]] ++;
        susedi [table[i+1][n-1]][br[table[i+1][n-1]]] = table[i][n-1];
        br[table[i+1][n-1]] ++;
    }
    dfs(r);
    cout << sums << endl;
    return 0;
}