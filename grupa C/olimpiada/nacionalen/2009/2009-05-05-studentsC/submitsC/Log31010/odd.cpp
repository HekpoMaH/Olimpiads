/*
TASK: odd
LANG: C++
*/
#include <cstdio>
#include <algorithm>
const int MAX = 1 << 20;
int numbers[MAX];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0;i < n; ++i) {
	scanf("%lld", &numbers[i]);
  }
  std::sort(numbers, numbers + n);
  int cnt_cur = 1;
  int special = -1;
  for (int i = 1;i < n; ++i) {
	if (numbers[i] == numbers[i - 1]) {
	  cnt_cur++;
	} else {
	  if (cnt_cur % 2 == 1) {
		special = numbers[i - 1];
		//printf("%d\n", special);
	  }
	  cnt_cur = 1;
	}
  }
  if (numbers[n - 1] == numbers[n - 2]) {
	cnt_cur++;
  } else {
	if (cnt_cur % 2 == 1) {
	  special = numbers[n - 1];
	  //printf("%d\n", special);
	}
	cnt_cur = 1;
  }
  printf("%d\n", special);
  return 0;
}
