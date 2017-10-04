#include <iostream>
using namespace std;

const long long M = 123456789;

int main()
{ long long n,p,q;
  cin >> n >> p >> q;
  cout << (p*(n-p+1) + (q-p)*(n-q+1))%M << endl;
  return 0;
}


