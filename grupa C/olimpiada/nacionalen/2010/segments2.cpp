#include<iostream>
#include<algorithm>
using namespace std;
const int N_max=200020;
struct point
{
  int x;
  int v;
  int w;
  long long int s;
  long long int c;
};
point a[N_max];
int n;
bool cmp(point a, point b)
{
  if(a.x<b.x)return true;
  if(a.x>b.x)return false;
  if(a.v<b.v)return true;
  return false;
}
int main()
{
  ios::sync_with_stdio(false);
  cin>>n;
  int x1,x2,w;
  for(int i=0;i<n;i++)
  {
    cin>>x1>>x2>>w;
    a[2*i].x=x1;
    a[2*i].v=1;
    a[2*i].w=w;
    a[2*i+1].x=x2;
    a[2*i+1].v=-1;
    a[2*i+1].w=-w;
  }
  n=2*n;
  sort(a,a+n,cmp);
  a[0].s=a[0].w;
  for(int i=1;i<n-1;i++)
  {
    a[i].s=a[i-1].s+a[i].w;
  }
  int x0=a[0].x;
  for(int i=1;i<n;i++)
  {
      if(a[i-1].x<a[i].x)a[i-1].c=a[i-1].s*(a[i].x-x0);
      x0=a[i].x;
  }
  long long int s=0;
  long long int m=0;
  long long int sum=0;
  for(int i=0;i<n-1;i++)if(a[i].x<a[i+1].x)
  {
    s+=a[i].c;
    if(s>m)m=s;
    if(s<0)s=0;
  }
  cout<<m<<endl;
  return 0;
}
