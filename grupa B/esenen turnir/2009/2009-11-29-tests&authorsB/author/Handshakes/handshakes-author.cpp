#include <iostream>
#define L 'L'

char A[100001];
long long swaps, waits, seconds;
int left_R, i;

int main() {
	std::cin>>A;
	for ( ; A[i]==L ; i++  );  // skip leading L
	for ( ; A[i] ; i++)
		if (A[i]==L) swaps+=left_R, seconds=left_R+waits++;
		else left_R++, (waits?waits--:0);
  std::cout<<seconds<<' '<<swaps<<std::endl;
  return 0;
}
