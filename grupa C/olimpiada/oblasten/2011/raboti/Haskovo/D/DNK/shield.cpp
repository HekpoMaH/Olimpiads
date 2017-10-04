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
  int n,a[110],b[110];
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  for(int i=0;i<n;i++)
  {
    cin>>b[i];
  }
  int min=999,min1=999;
  for(int i=0;i<n;i++)
  {
    if(a[i]+b[i]<min){min=a[i]+b[i];}
  }
  for(int i=0;i<n;i++)
  {
    if(a[i]+b[n-i-1]<min1){min1=a[i]+b[n-i-1];}
  }
  if(min<min1){cout<<min1<<endl;}
  else{cout<<min<<endl;}
  return 0;
}

