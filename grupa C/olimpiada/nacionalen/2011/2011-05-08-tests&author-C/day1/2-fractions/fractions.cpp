#include<iostream>
using namespace std;

int main()
{
  int z;
  long long m,n;
  cin >> z >> m >> n;
 long long i=1, j=1;
  for(int p=2;p<=z;p++)
  { long long  int k=m*p/n+1;
    if(k*j<p*i) {i=k; j=p;}
  }
  cout << i << " " << j << endl;
}
