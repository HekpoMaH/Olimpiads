#include<iostream>
#include<fstream>
#include<cmath>
#include<cstring>
#include<string>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;
long long n,t,a[1000],na,kr,otg[1000],br;
string b;
void solve()
{
  cin>>n;
  for(int i=0;i<n;i++)cin>>a[i];
  sort(a,a+n);
  //for(int i=0;i<n;i++)b+=a[i]+'0';
 // long long mn=2005,mx=0;
 int l=0,r=n-1,mn=2009,mx=0;
  while(l<r)
  {
    na=a[l];
    kr=a[r];
    if(na+kr>mx)mx=na+kr;
    if(na+kr<mn)mn=na+kr;
    l++;r--;
  }
  br++;
  otg[br]=mx-mn;
}
int main()
{
  cin>>t;
  for(int w=0;w<t;w++)
  {
    solve();
  }
  for(int w=1;w<=br;w++)
  {
    cout<<otg[w]<<endl;
  }
  return 0;
}
