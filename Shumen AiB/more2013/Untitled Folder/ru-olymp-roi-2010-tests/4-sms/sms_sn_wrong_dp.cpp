#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstdio>
#include <algorithm>

#define LMAX 200000
#define INF int(1E+9)

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define all(v) v.begin(), v.end()

#define LEVEL 5

vector<string> people[LEVEL];
vector<int> ans[LEVEL], parent[LEVEL];

void read_data() {
  char buf[256];
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

int cost(const string& a, const string& b) {
  int result = 10;
  forn (i, min(a.size(), b.size())) {
    if (a[i] == b[i])
      --result;
    else
      break;  
  }
  return result;
}

bool solve() {
  ans[0].push_back(0);
  parent[0].push_back(-1);
  for (int i = 1; i < LEVEL; ++i) {
    if (people[i].size() == 0) return false;
    int k = people[i].size();
    ans[i].resize(k);
    parent[i].resize(k);
    int ptr = 0;
    forn (j, k) {
      const string& s = people[i][j];
      while (ptr + 1 < people[i - 1].size() && people[i - 1][ptr + 1] <= s) ++ptr;
      ans[i][j] = ans[i - 1][ptr] + cost(s, people[i - 1][ptr]);
      parent[i][j] = ptr;
    }
    ptr = people[i - 1].size() - 1;
    for (int j = k - 1; j >= 0; --j) {
      const string& s = people[i][j];
      while (ptr - 1 >= 0 && people[i - 1][ptr - 1] >= s) --ptr;
      int delta = ans[i - 1][ptr] + cost(s, people[i - 1][ptr]);
      if (ans[i][j] > delta) {
        ans[i][j] = delta;
        parent[i][j] = ptr;
      }   
    }
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
