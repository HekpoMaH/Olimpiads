#include<iostream>
#include<algorithm>
using namespace std;
struct point
{
  int x,v;
};
point a[200009];
long long n,b,d,mx,sum;
bool prov(point a, point b)
{
  if(a.x<b.x)return true;
  if(a.x>b.x)return false;
  if(a.v<b.v)return true;
  return false;
}
int main()
{
  cin>>n;
  n*=2;
  for(int i=0;i<n/2;i++)
  {
    cin>>a[2*i].x;
    a[2*i].v=1;
    cin>>a[2*i+1].x;
    a[2*i+1].v=-1;
  }
  sort(a,a+n,prov);
  //for(int i=0;i<n;i++)cout<<a[i].x<<" "<<a[i].v<<endl;
  for(int i=0;i<n;i++)
  {
    d+=a[i].v;
    if(mx<d)mx=d;
  }
  d=0;
  int last=a[0].x-1;
  for(int i=0;i<n;i++)
  {
    d+=a[i].v;
    if(d==mx)
    {
      sum+=a[i+1].x-a[i].x+1;
      if(a[i].x==last)sum--;
      last=a[i+1].x;
    }
  }
  cout<<sum<<endl;
  return 0;
}
