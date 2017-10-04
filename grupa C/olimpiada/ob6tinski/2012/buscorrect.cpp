#include<iostream>
#include<algorithm>
using namespace std;
struct card
{
  int p,q,s;
};
int n,a,b,tek,sbor,sbor2,l1;
card c[101];
bool cmp(card a,card b)
{
  if(a.p>b.p)return false;
  if(a.p<b.p)return true;
  if(a.q>b.q)return false;
  return true;
}
int main()
{
  cin>>n>>a>>b;
  for(int i=0;i<n;i++)cin>>c[i].p>>c[i].q>>c[i].s;
  sort(c,c+n,cmp);
  //for(int i=0;i<n;i++)cout<<c[i].p<<" "<<c[i].q<<" "<<c[i].s<<endl;
  //tek=a;
  for(int i=0;i<n;i++)
  {
    //cout<<sbor<<endl;
    if(c[i].q>a&&l1==0)
    {
      if(c[i].p<b&&c[i].q>b){sbor+=b-a;break;}
      if(c[i].q-a>=c[i].s)sbor+=c[i].s;
      if(c[i].q-a<c[i].s)sbor+=c[i].q-a;
      l1=1;
      continue;
    }
    else if(b>=c[i].p&&b<=c[i].q)
    {
      if(b-c[i].p>=c[i].s)sbor+=c[i].s;
      if(b-c[i].p<c[i].s)sbor+=b-c[i].p;
      break;
    }
    else if(l1==1)sbor+=c[i].s;
  }
  cout<<sbor<<endl;
  return 0;
}
