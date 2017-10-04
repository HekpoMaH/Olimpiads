#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <set>

#include "random.h"

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)

int tst = 0;

long long besta, bestb, bestc;

long long getAns(long long n) {
    double ac = sqrt(n / 6);
    double a0 = floor(ac);
    long long a = round(a0);
    long long ans = 0;
    int cnt = 0;
    while (true) {
      double bc = sqrt(a * a + n / 2.0) - a;
      if (a * bc * bc < ans)
        break;
      double b0 = floor(bc);
      long long b = round(b0);
      while (true) {
        double cc = (n - 2 * a * b) / 1.0 / (2 * a + 2 * b);
        long long c = (n - 2 * a * b) / (2 * a + 2 * b);
        if (ans < a * b * c) {
          besta = a;
          bestb = b;
          bestc = c;
        }
        ans = max(ans, a * b * c);
        if (a * b * cc < ans)
          break;
        --b;
      }
      --a;
    }
    return ans;
  }

FILE* descr = fopen("description", "w");

void write_test(long long n) {
  assert(n <= 10000000000000LL);
  char buf[256];
  sprintf(buf, "%02d", ++tst); 
  FILE* f = fopen(buf, "w");
  fprintf(f, "%I64d\n", n);
  fclose(f);

  fprintf(descr, "N = %I64d\n", n);

  cerr << "Test " << tst << ": " << n << endl; 
}

void write_vector(vector<long long> a) {
  sort(a.begin(), a.end());
  forn (i, a.size()) {
    write_test(a[i]);
  }
}

void gen_random(long long min_n, long long max_n, int amount) {
  vector<long long> a;
  forn (i, amount) {
    long long n = min_n + rndLong(max_n - min_n + 1);
    a.push_back(n);    
  }
  write_vector(a);  
}

bool greedy(long long n) {
    if (n > 200) {
      if (abs(besta - bestb) < 3 || abs(besta - bestc) < 3 || abs(bestb - bestc) < 3) {
        return true;
      }
    }  else
    if (n > 100) {
      if (abs(besta - bestb) < 2 || abs(besta - bestc) < 2 || abs(bestb - bestc) < 2) {
        return true;
      }
    }
    return false;
}

void gen_random_two_larger(long long min_n, long long max_n, int amount) {
  vector<long long> a;
  set<long long> used;
  int it = 0;
  forn (i, amount) {
    long long n = min_n + rndLong(max_n - min_n + 1);
    if (n < min_n) {
      --i;
      continue;
    }
    if (used.count(n)) {
      --i;
      continue;
    }
    getAns(n);
    double mid = sqrt(n / 6.0) + 0.5;
    int cnt = 0;
    if (n >= 10000) mid += 5;
    if (n >= 1000000) mid += 10;
    if (n >= 1000000000) mid += 10;
    if (besta > mid) cnt++;
    if (bestb > mid) cnt++;
    if (bestc > mid) cnt++;

    if (cnt < 2) {
      --i;
      continue;
    }
    if (greedy(n)) {
      --i;
      continue;
    }
    a.push_back(n);
    used.insert(n); 
  }
  write_vector(a);  
}

void gen_random_no_square2(long long min_n, long long max_n, int amount) {
  vector<long long> a;
  forn (i, amount) {
    long long n = min_n + rndLong(max_n - min_n + 1);
    if (n < 6) {
      --i;
      continue;
    }
    getAns(n);
    if (besta == bestb || besta == bestc || bestb == bestc) {
      --i;
      continue;
    }
    a.push_back(n);    
  }
  write_vector(a);  
}


void gen_random_no_square(long long min_n, long long max_n, int amount) {
  vector<long long> a;
  forn (i, amount) {
    long long n = min_n + rndLong(max_n - min_n + 1);
    if (n < 6) {
      --i;
      continue;
    }
    getAns(n);
    if (n > 200) {
      if (abs(besta - bestb) < 3 || abs(besta - bestc) < 3 || abs(bestb - bestc) < 3) {
        --i;
        continue;
      }
    }  else
    if (n > 100) {
      if (abs(besta - bestb) < 2 || abs(besta - bestc) < 2 || abs(bestb - bestc) < 2) {
        --i;
        continue;
      }
    }
    a.push_back(n);
  }
  write_vector(a);  
}

int main() {

  initrand(13);

  vector<long long> a;
  forn (i, 2) a.push_back(6 * (1 + i) * (1 + i));
  write_vector(a);

  a.clear();
  a.push_back(16);
  a.push_back(31);
  a.push_back(64);
  a.push_back(76);
  write_vector(a);

  gen_random_no_square(6, 100, 4);

  gen_random_two_larger(1000, 5000, 2);
  gen_random_no_square(1000, 5000, 3);

  gen_random_two_larger(11000, 1000000, 7);
  gen_random_no_square(11000, 1000000, 8);

  gen_random_two_larger(10000000, 100000000LL, 3);
  gen_random_no_square(10000000, 100000000LL, 2);

  gen_random_two_larger(3000000000LL, 9000000000LL, 4);

  a.clear();
  forn (i, 5) {
    long long n = 100000 + rndLong(200000 + 1);
    n = 2 * n * (3 * n - 1);
    a.push_back(n);
  }
  write_vector(a);

  a.clear();
  forn (i, 5) {
    long long n = 1000000 + rndLong(290000 + 1);
    n = 2 * n * (3 * n - 1);
    a.push_back(n);
  }
  write_vector(a);

  write_test(10000000000000LL);

  return 0;
}
