/* TASK: Towers
   Author: Yordan Chaparov
   SOLUTION: O(N^2)    
*/ 
#include<bits/stdc++.h>
using namespace std;
int m;
int p[1 << 17];

// Make sure we don't have conflicting values.
// Plus one everythin >= last number.
// After each call to reassign, p[] is permutation of {1..m}
// Relative order of everything that we compared before is preserved.
//
void reassign() {
  for (int i = 0; i + 1 < m; ++i) {
    if (p[i] >= p[m - 1]) {
      ++p[i];
    }
  }
}

void add_num(int l) {
  int k = 0;
  int i = m - 1;
  // Must skip l numbers.
  //
  while (l) {
    // We will only cover numbers not covered before:
    // must be greater than previous covered number.
    //
    if (p[i] > k) {
      k = p[i];
      --l;
    }
    --i;
  }
  p[m++] = k + 1;
  reassign();
  for(int i=0;i<m;i++)cout<<p[i]<<" ";
  cout<<"\n";
}

int main() {
  int n, l;
  scanf("%d", &n);
  m = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &l);
    add_num(l);
  }

  for (int i = 0; i < n; ++i) {
    printf("%d\n", p[i]);
  }
  return 0;
}
