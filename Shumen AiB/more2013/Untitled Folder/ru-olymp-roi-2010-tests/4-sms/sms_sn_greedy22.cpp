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
string s, t;

string b1, b2, b3;
int best = INF;

void read_data() {
  char buf[256];
  scanf("%s", buf);
  s = buf;
  scanf("%s", buf);
  t = buf;

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

int cost(const string& s1, const string& s2, const string& s3, const string& s4, const string& s5) {
  return cost(s1, s2) + cost(s2, s3) + cost(s3, s4) + cost(s4, s5);
}

string find_best(const string& a, const vector<string>& v) {
  int best = 0;
  int dst = INF;
  forn (i, v.size()) {
    int cur = cost(a, v[i]);
    if (cur < dst) {
      dst = cur;
      best = i;
    }
  }                
  return v[best];    
}

bool solve() {
  string tb3 = find_best(t, people[3]);
  string tb2 = find_best(tb3, people[2]);
  string tb1 = find_best(tb2, people[1]);

  int tbest = cost(s, tb1) + cost(tb1, tb2) + cost(tb2, tb3) + cost(tb3, t);

  if (tbest < best) {
    best = tbest;
    b1 = tb1;
    b2 = tb2;
    b3 = tb3;
  }

  return true;
}

void write_answer() {
  printf("%d %d\n", best, 5);
  printf("%s\n%s\n%s\n%s\n%s\n",
      s.c_str(), b1.c_str(), b2.c_str(), b3.c_str(), t.c_str());
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
