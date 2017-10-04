#include<iostream>
#include<cmath>
using namespace std;
long long s;
int n,a[128],br,mbr=10000,b[128][128];
void read()
{
  int i,j;
  cin>>s>>n;
  for (i=0;i<n;i++)
  cin>>a[i];
  for (i=0;i<n;i++)
  for (j=0;j<n-1;j++)
  if (a[j]<a[j+1])
  swap(a[j],a[j+1]);
}
void solve()
{
  int i,j,ost;
  for (i=0;i<n;i++)
  {
    br=s/a[i];
    ost=s-(br*a[i]);
    break;
  }
  cout<<br+2<<endl;
}
int main()
{

  read();
  solve();
return 0;
}

/*
10000 7
12 1 11 30 14 2 18
*/