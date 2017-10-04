#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,i,inp,br;
long long ans1,ans2;

int main()
{

  scanf("%d",& n);

  if (n <= 200000)
  {
    short int a[200100],x;
    for(i=1;i<=n+10;i++) a[i]=0;

    for(i=1;i<=n;i++) { scanf("%d",& inp); a[i]=(short int)inp;}

    sort(a+1,a+n+1);

    for(i=1;i<=n;i++)
     if (a[i]!=a[i-1] && a[i]!=a[i+1])
     {
       if (ans1 == 0) ans1=(long long)a[i];
       else ans2=(long long)a[i];
     }
    printf("%d %d\n", (int)ans1, (int)ans2);
  }
  else
  {
    bool a[100010];
    long long x;

    for(i=1;i<=100000;i++) a[i]=false;

    br=0;
    for(i=1;i<=n;i++)
    {
      scanf("%lld",& x);
      if (x <= 100000)
      {
        a[x]^=1;
        br++;
      }
    }

    if (br == n)
    {
      for(i=1;i<=100000;i++)
       if (a[i] == true)
       {
         if (ans1 == 0) ans1=(long long)i;
         else ans2=(long long)i;
       }
      printf("%d %d\n", (int)ans1, (int)ans2);
    }
  }
return 0;
}
