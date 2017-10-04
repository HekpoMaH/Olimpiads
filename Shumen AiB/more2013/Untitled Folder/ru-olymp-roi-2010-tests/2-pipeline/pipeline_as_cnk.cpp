// Solution - C(n, k) - recursive full search
#include <cstdio>

const int MAXN = 2048;

int n, m, k;
int con[MAXN][MAXN];
int adj[MAXN];

bool ok;
bool take[MAXN];

int cur, zeros;
int taken[MAXN];

void go(int cur, int v){
  if (cur == k){
    if (zeros == m){
      ok = true;
    }
    return;
  }
  for (int i=v; i<=n-k+cur+1; i++){
    int nz = adj[i];
    taken[cur] = i;
    take[i] = true;
    for (int j=0; j<cur; j++) nz -= con[i][taken[j]];
    zeros += nz;
    go(cur + 1, i + 1);
    if (ok) return;
    zeros -= nz;
    take[i] = false;
  }
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
  go(0, 1);
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
