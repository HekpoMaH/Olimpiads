// Solution - 2^n * n, recursive full search
#include <cstdio>

const int MAXN = 2048;

int n, m, k;
bool con[MAXN][MAXN];
int adj[MAXN];

bool ok;
bool take[MAXN];

int cur;

void go(int v){
  if (v > n){
    bool all = true;
    for (int i=1; i<=n; i++){
      all &= (adj[i] == 0);
    }
    if (all && cur <= k){
      ok = true;
    }
    return;
  }
  go(v + 1);
  if (ok) return;
  take[v] = true;
  cur++;
  for (int i=1; i<=n; i++){
    if (con[v][i] && !take[i]){
      adj[v]--;
      adj[i]--;
    }
  }
  go(v + 1);
  if (ok) return;
  take[v] = false;
  cur--;
  for (int i=1; i<=n; i++){
    if (con[v][i] && !take[i]){
      adj[v]++;
      adj[i]++;
    }
  }
}

void solve_2n(){
  go(1);
}

void add_more(){
  int ck = 0;
  for (int i=1; i<=n; i++){
    ck += take[i];
  }
  for (int i=1; i<=n; i++){
    if (!take[i] && ck < k){
      take[i] = true;
      ck++;
    }
  }
}

int main(){
  freopen("pipeline.in", "r", stdin);
  freopen("pipeline.out", "w", stdout);
  scanf("%d%d%d", &n, &m, &k);
  for (int i=0; i<m; i++){
    int x, y;
    scanf("%d%d", &x, &y);
    con[x][y] = con[y][x] = true;
    adj[x]++;
    adj[y]++;
  }
  solve_2n();
  if (!ok){
    printf("No\n");
  }
  else{
    printf("Yes\n");
    add_more();
    for (int i=1; i<=n; i++){
      if (take[i]) printf("%d ", i);
    }
    printf("\n");
  }
  return 0;
}
