#include <cstdio>
#include <algorithm>
using namespace std;

const int N_max=200020;
struct point {int x; int v;};
point a[N_max];
int n;

bool cmp(point a, point b)
{ if(a.x < b.x)return true;
  if(a.x > b.x)return false;
  if(a.v < b.v)return true;
  return false;
}

int main()
{
  scanf("%d",&n);
  n=2*n;
  for(int i=0;i<n/2;i++)
   {scanf("%d", &a[2*i].x); a[2*i].v=1;
    scanf("%d", &a[2*i+1].x); a[2*i+1].v=-1;
   }

  sort(a, a+n, cmp);

int d=0;
int m=0;
for(int i=0;i<n;i++)
{
  d += a[i].v;
  if(m<d) m=d;
}

int s=0;
d=0;
int last=a[0].x-1;
for(int i=0;i<n;i++)
{
  d += a[i].v;
  if(d==m)
  {
    s = s + a[i+1].x-a[i].x+1;
    if(a[i].x==last) s--;

    last=a[i+1].x;
  }
}
printf("%d\n",s);
}
