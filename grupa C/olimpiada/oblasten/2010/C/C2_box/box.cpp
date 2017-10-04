#include <iostream>
using namespace std;
struct par {long long w,h;};
par a[6]; 

int cmp(par p, par q)
{
  if (p.w<q.w)return 1;
  else if (p.w>q.w)return 0;
       return (p.h<q.h);  
}
int main()
{
  for(int i=0;i<6;i++)
  {
     cin>>a[i].w>>a[i].h;
     if (a[i].w>a[i].h)swap(a[i].w,a[i].h);
  }
  sort(a,a+6,cmp);
  bool f=a[0].w==a[1].w&&a[0].w==a[2].w&&a[0].w==a[3].w
       &&a[0].h==a[1].h&&a[0].h==a[4].w&&a[0].h==a[5].w
       &&a[2].h==a[3].h&&a[2].h==a[4].h&&a[2].h==a[5].h;
  if (f)cout<<a[0].w*a[0].h*a[2].h<<endl;
  else cout<<"0"<<endl;
  return 0;
}

