#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,i,a[32],b[32],seq[32],ans,curr,x,y,x2,y2,t,t1;
bool used[32];

void check()
{
  int j;

  curr=0;
  x=0;y=0;

  for(j=1;j<=n;j++)
  {
    x2=a[seq[j]];y2=b[seq[j]];
    if (x > x2) swap(x,x2);
    if (y > y2) swap(y,y2);

    if (x2-x < y2-y) t1=(x2-x)+(y2-(y+x2-x));
    else t1=(y2-y)+(x2-(x+y2-y));

    curr+=t1;

    x=a[seq[j]];
    y=b[seq[j]];
  }

  if (curr < ans) ans=curr;
}
void solve(int x)
{
  int i;
  if (x > n) check();
  else
  for(i=1;i<=2*n;i++)
   if (!used[i])
   {
     seq[x]=i;
     used[i]=true;

     solve(x+1);

     used[i]=false;
     seq[x]=0;
   }
}

int main()
{
  scanf("%d",& n);
  for(i=1;i<=2*n;i++) scanf("%d%d",& a[i],& b[i]);

  ans=1<<30;
  solve(1);
  printf("%d\n", ans);
return 0;
}
