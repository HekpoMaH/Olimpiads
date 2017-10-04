#include<iostream>
using namespace std;

bool isPrime[10001];
int x, a=0, i, j;

int main()
{
  cin >> x;
  isPrime[1]=false;
  for (i=2;i<=x;i++) isPrime[i]=true;
  for (i=2;i<=x;i++) {
      if (isPrime[i]) {
           j=2*i;
           while (j<=x) {
                 isPrime[j]=false;
                 j+=i;
           }
                        
      }
  }
  i=2; j=x-2;
  while (i<=j) {     
      if (isPrime[i]&&isPrime[j])a++;
      i++; j--;  
  }
  cout << a << endl;
}
