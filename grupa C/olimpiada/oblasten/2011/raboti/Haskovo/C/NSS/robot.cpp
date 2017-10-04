#include <iostream>
#include <vector>
#include <queue>

using namespace std;

queue <int> q;
vector <int> g[10010];
int m,n,r,k;
short d1[] = {-1,0,0,1};
short d2[] = {0,-1,1,0};
int a[110][110];
bool used[10010];
int mnturns[10010];

bool valid (int x,int y)
{
  if (x >= 0 && x < m && y >= 0 && y < n) return true;
  return false;
}

void makebig()
{

}

long long find_sum()
{
  long long sm = 0;
  int turn = 0;
  q.push (r);
  mnturns[r] = 0;
  while (q.size() > 0 && turn <= k){
    for (int i = 0; i < g[q.front()].size(); i ++){
      if (used[g[q.front()][i]] == false){
        mnturns[g[q.front()][i]] = mnturns[q.front()] + 1;
        turn = mnturns[g[q.front()][i]];
        if (mnturns[g[q.front()][i]] == k) sm += g[q.front()][i];
        q.push(g[q.front()][i]);
        used[g[q.front()][i]] = true;
      }
    }
    q.pop();
  }
  cout << sm << endl;
  return sm;
}

int main()
{
  cin >> m >> n >> r >> k;
  int num = 1;
  for (int i = 0; i < m; i ++){
    for (int  j = 0; j < n; j ++){
      a[i][j] = num;
      num ++;
    }
  }
  for (int i = 0; i < m; i ++){
    for (int  j = 0; j < n; j ++){
      //cout << a[i][j] << " ";
      for (int u = 0; u < 4; u ++){
        if (valid (i + d1[u],j + d2[u]) == true){
          g[a[i][j]].push_back(a[i + d1[u]][j + d2[u]]);
        }
      }
    }
  }
  find_sum();
  return 0;
}
/*
long long find_sum()
{
  long long sm = 0;
  int turn = 0;
  q.push (r);
  mnturns[r] = 0;
  while (q.size() > 0 && turn <= k){
    for (int i = 0; i < g[q.front()].size(); i ++){
      if (used[g[q.front()][i]] == false){
        mnturns[g[q.front()][i]] = mnturns[q.front()] + 1;
        turn = mnturns[g[q.front()][i]];
        if (mnturns[g[q.front()][i]] == k) sm += g[q.front()][i];
        q.push(g[q.front()][i]);
        used[g[q.front()][i]] = true;
      }
    }
    q.pop();
  }
  cout << sm << endl;
  return sm;
}
*/
