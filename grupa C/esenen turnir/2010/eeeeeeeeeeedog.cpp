#include<iostream>
#include<math.h>
#
using namespace std;
long m,n,k;
int main()
{
  cin>>m>>n>>k;
  int raz;
  if(n>=k)raz=n-k;
  else raz=k-n;
  if(m%raz==0)cout<<m/raz<<endl;
  else cout<<m/raz+1<<endl;
  return 0;
}

