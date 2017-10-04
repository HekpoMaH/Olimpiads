#include<iostream>
#include<algorithm>
#include<iomanip>
#include<math.h>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;
int a[20],n,transfer;
double f;
int main()
{
  cin>>n;
  //cin>>transfer;
  for(int i=0;i<n;i++)cin>>a[i];
  //f=(double)transfer;
  //cout<<setiosflags(ios::fixed)<<setprecision(3)<<f<<endl;
  sort(a,a+n);
  for(int i=0;i<n;i++)cout<<a[i]<<" ";
  cout<<endl;
  return 0;
}
