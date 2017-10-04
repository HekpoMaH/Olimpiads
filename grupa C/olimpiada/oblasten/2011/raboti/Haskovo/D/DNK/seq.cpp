//
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;
int main()
{
  double a[110000];
  long long int i=0;
  cin>>a[0];
  while(a[i]!=0)
  {
    i++;
    cin>>a[i];
  }
  int br=1,max=-999;
  for(long long int j=0;j<=i;j++)
  {
    if(a[j]>=a[j-1]){br++;}
    else
    {
      if(max<br){max=br;}
      br=1;
    }
  }
  cout<<max<<endl;
  return 0;
}

