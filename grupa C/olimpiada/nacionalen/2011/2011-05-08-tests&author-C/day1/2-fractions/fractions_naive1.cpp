#include<iostream>
using namespace std;

int main()
{
  long long int z,m,n;
  cin >> z >> m >> n;
  long long int i=1, j=1;
  for(int p=2;p<=z;p++)
  { long long int k=1;
    while(m*p>=k*n) k++;
    if(k*j<p*i) {i=k; j=p;}
  }
  cout << i << " " << j << endl;
}
