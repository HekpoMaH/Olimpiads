#include<iostream>
using namespace std;

int n, k;

long long int b[50];

int main()
{
  cin >> n >> k;
  b[1]=1;
  b[2]=1;
  for(int i=3;i<=n;i++)
  {
    long long int s=0;
    int j0 = i-k;
    if(j0<1) j0=1;
    for(int j=j0;j<=i-1;j++) s += b[j];
    b[i]=s;
  }
  cout << b[n] << endl;
}
