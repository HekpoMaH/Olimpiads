#include<cstdio>
#include<algorithm>
using namespace std;
struct point
{
  long long x,v;
};
point a[200002];
bool cmp(point z,point y)
{
  if(z.x<y.x)return true;
  if(z.x>y.x)return false;
  if(z.v<y.v)return true;
  return false;
}
long long n,mxd,td,br;/*mxd->makcuma/\Ha debe/\uHa
                     td->TeKu|_|_|Ta debe/\uHa
                     br->broi MecTa c MakcuMa/\Ha debelina*/
int main()
{
  scanf("%I64d",&n);
  n*=2;
  for(long long i=0;i<n/2;i++)
  {
    scanf("%I64d",&a[2*i]);
    a[2*i].v=1;
    scanf("%I64d",&a[2*i+1]);
    a[2*i+1].v=-1;
  }
  sort(a,a+2*n,cmp);
  for(int i=0;i<n;i++)printf("%I64d %I64d\n",a[i].x,a[i].v);
  //HaMupaMe MakcuMa/\HaTa debelina
  for(long long i=0;i<n;i++)
  {
    td+=a[i].v;
    if(td>mxd)mxd=td;
  }
  td=0;
  int last=a[0].x-1;
  //HaMupaMe u prebroqvame MecTaTa c MakcuMa/\Ha debelina
  for(long long i=0;i<n;i++)
  {
    td+=a[i].v;
    if(td==mxd)
    {
      br+=a[i+1].x-a[i].x+1;
      if(a[i].x==last)br--;
      last=a[i+1].x;
    }
  }
  printf("%I64d\n",br);
  return 0;
}
