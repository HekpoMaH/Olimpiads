#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstdio>
#include <algorithm>

#define LMAX 10
#define INF int(1E+9)

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define all(v) v.begin(), v.end()

#define LEVEL 5

vector<string> people[LEVEL];
vector<int> ans[LEVEL], parent[LEVEL];

void read_data() {
  char buf[LMAX + 1];
  scanf("%s", buf);
  string s(buf);
  scanf("%s", buf);
  string t(buf); 

  forn (i, LEVEL) {
    int n;
    scanf("%d", &n);
    forn (j, n) {
      scanf("%s", buf);
      people[i].push_back(buf);    
    }
    sort(all(people[i]));
  }
  people[0] = vector<string>(1, s);
  people[LEVEL - 1] = vector<string>(1, t);
}

int lcp(const string& a, const string& b) {
  forn (i, min(a.length(), b.length())) {
    if (a[i] != b[i]) return i;  
  }
  return min(a.size(), b.size());
}

void update(int i, int dir) {
  int ptr = dir == 1 ? -1 : people[i - 1].size();
  int start = dir == 1 ? 0 : people[i].size() - 1;
  int end = dir == 1 ? people[i].size() : -1;
  vector<int> group(LMAX + 1, INF);
  vector<int> group_min(LMAX + 1, -1);
  for (int j = start; j != end ; j += dir) {
    const string& s = people[i][j];
    int lcp_last = 0;
    if (j - dir >= 0 && j - dir < people[i].size())
        lcp_last = lcp(s, people[i][j - dir]);
    for (int t = lcp_last + 1; t <= LMAX; ++t) {
      if (group[lcp_last] > group[t]) {
        group[lcp_last] = group[t];
        group_min[lcp_last] = group_min[t];
      }
      group[t] = INF;
    }
    while ((dir == 1 && ptr + 1 < people[i - 1].size() && people[i - 1][ptr + 1] < s) ||
       (dir == -1 && ptr - 1 >= 0 && people[i - 1][ptr - 1] > s)) {
      ptr += dir;
      int lcp_cur = lcp(people[i - 1][ptr], s);
      if (group[lcp_cur] > ans[i - 1][ptr]) {
        group[lcp_cur] = ans[i - 1][ptr];
        group_min[lcp_cur] = ptr;
      }
    }
    forn (t, LMAX + 1) {
      int res = group[t] + LMAX - t;
      if (res < ans[i][j]) {
        ans[i][j] = res;
        parent[i][j] = group_min[t];
      }
    }
  }
}

bool solve() {
  ans[0].push_back(0);
  parent[0].push_back(-1);
  for (int i = 1; i < LEVEL; ++i) {
    if (people[i].size() == 0) return false;
    int k = people[i].size();
    ans[i].resize(k);
    parent[i].resize(k);
    forn(j, k) ans[i][j] = INF;
    update(i, 1);
    update(i, -1);
  }
  return true;
}

void write_answer() {
  printf("%d %d\n", ans[LEVEL - 1][0], 5);
  vector<string> res;
  int v = 0;
  for (int i = LEVEL - 1; i >= 0; --i) {
    res.push_back(people[i][v]);
    v = parent[i][v];  
  }  
  reverse(all(res));
  forn (i, res.size()) {
    printf("%s\n", res[i].c_str());
  }
}

int main() {
  freopen("sms.in", "r", stdin);
  freopen("sms.out", "w", stdout);
  
  read_data();
  if (solve()) {
    write_answer();
  } else {
    printf("-1\n");
  }

  return 0;
}
