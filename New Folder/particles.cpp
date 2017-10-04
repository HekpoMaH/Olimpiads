#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
long long n,nrj;
struct point
{
  long long pos;
  long long sp;
};
point x[400001],y[400001];
long long indx=1,indy=1;
bool cmp(point a,point b)
{
  if((a.sp<b.sp)||(a.sp==b.sp&&a.pos<b.pos))return true;
  return false;
}
void input()
{
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    scanf("%d",&x[i].pos);
    scanf("%d",&x[i].sp);
    x[i].sp*=x[i].pos;
  }
  for(int i=1;i<=n;i++)
  {
    scanf("%d",&y[i].pos);
    scanf("%d",&y[i].sp);
    y[i].sp*=y[i].pos;
  }
}
int main()
{
  input();
  sort(x,x+n,cmp);
  sort(y,y+n,cmp);
  while(indx<=n&&indy<=n)
  {
    if(x[indx].sp==y[indy].sp)
    {
      nrj++;
      indx++;indy++;
    }
    else if(x[indx].sp<y[indy].sp)indx++;
    else indy++;
  }
  cout<<nrj<<endl;
  return 0;
}
