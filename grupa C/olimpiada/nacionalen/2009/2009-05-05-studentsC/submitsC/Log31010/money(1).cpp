/*
TASK: money
LANG: C++
*/
#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int numbers[200000];
int main() {
  scanf("%d", &n);
  for (int i = 0;i < n; ++i) {
	scanf("%d", &numbers[i]);
  }
  sort(numbers, numbers + n);
  int stay = 2;
  int ans = 1;
  int i;
  for (i = 1;i < n - 2 && stay < n; ++i) {
	while (numbers[stay] < numbers[i] + numbers[i - 1] && stay < n) {
	  ++stay;
	}
	if (ans < stay - i + 1) {
	  ans = stay - i + 1;
	}
  }
  printf("%d\n", ans);
  return 0;
}
