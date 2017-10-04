#include<iostream>
#include<algorithm>
using namespace std;
struct rocket
{
  long long h;long long p;
};
rocket a[10006];
int n;
bool cmp(rocket a,rocket b)
{
  if(a.h<b.h)return false;
  return true;
}
int main()
{
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>a[i].h;
    a[i].p=i;
  }
  sort(a,a+n,cmp);
  int b=0,br=0,mx=0;
  for(int i=0;i<n;i++)
  {
    b=i;
    for(int j=i;j<n;j++)
    {
      if(a[b].p<a[j].p){br++;b=j;}
    }
    if(mx<br)mx=br;
  }
  cout<<br<<endl;
  return 0;
}
