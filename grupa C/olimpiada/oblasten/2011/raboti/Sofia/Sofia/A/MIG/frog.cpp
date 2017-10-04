#include <cstdio>
#include <math.h>
#define MAX2N 12
#define INFJ 1000000
using namespace std;

int n;

struct cords{

   int x;
   int y;
};

cords a[MAX2N];
int jmpt = 0;
int jmp = INFJ;



void solve(int ip, int s)
{
   for(int i = 0; i < 2*n; i++)
   {
      if(i != ip)
      {
      //printf("%d %d ", ip, i);
      int m;
      if(fabs(a[i].x - a[ip].x) > fabs(a[i].y - a[ip].y)) { m = fabs(a[i].x - a[ip].x); jmpt += m; }
      else { m = fabs(a[i].y - a[ip].y); jmpt += m; }

      if(s == n) {if(jmpt < jmp) { jmp = jmpt; }}
      else { solve(i, s+1); }

      jmpt = jmpt - m;
      }
   }

}


int main()
{
   scanf("%d", &n);

   for(int i=0; i<2*n; i++)
   {
      scanf("%d %d", &a[i].x, &a[i].y);
   }


      for(int i1=0; i1 < 2*n; i1++)
      {
         if(a[i1].x > a[i1].y) jmpt = a[i1].x;
         else jmpt = a[i1].y;

         solve(i1, 2);

      }

   printf("%d\n", jmp);




}
