// task: btree
// author: Mladen Manev

#include<iostream>
using namespace std;

int p;

int sol(long long n)
{
  int a[4]={0,0,0,0};
  int r;
  while(n != 0)
  {
    r = n % p;
    n /= p;
    if (r < 3) a[r]++;
    else a[3]++;
  }
  if(a[3] > 0) return 0;
  if(a[1] == 1 && a[2] > 0) return 1;
  if(a[1] == 2 && a[2] == 0) return 1;
  return 0;
}

int main()
{
  long long n1, n2, n3, n4;
  cin >> p >> n1 >> n2 >> n3 >> n4;
  cout << sol(n1) << " " << sol(n2) << " " << sol(n3) << " " << sol(n4) << endl;
  return 0;
}
