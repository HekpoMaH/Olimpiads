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

bool solve() {
  forn (i, people[1].size())
    forn (j, people[2].size()) { 
      forn (k, people[3].size()) {
        int delta = cost(s, people[1][i]) + cost(people[1][i], people[2][j]) +
                    cost(people[2][j], people[3][k]) + cost(people[3][k], t);
        if (delta < best) {
          best = delta;
          b1 = people[1][i];
          b2 = people[2][j];
          b3 = people[3][k];
        }
      }
  }
  return best != INF;
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
