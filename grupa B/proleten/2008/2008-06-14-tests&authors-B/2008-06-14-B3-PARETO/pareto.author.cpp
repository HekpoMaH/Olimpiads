#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

struct point
{int x; int y; int k; int b;};

point p[1000000];
int n;

bool cmp(point p1, point p2)
{
  if(p1.x>p2.x) return true;
  if(p1.x==p2.x)
   if(p1.y<p2.y) return true;
  return false;     
}

void search()
{
  int c=0;
  int x0;
  int y0=0;
  int i=1;
  p[n+1].x=-1;
  p[n+1].y=-1;
  
  while(i<=n)
  {
   x0=p[i].x;
   while(p[i].x==x0) i++;
   if(p[i-1].y>y0) 
    {c++; 
     p[i-1].b=1;
// printf("%c %d %d\n",(char)(p[i-1].k-1+'A'), p[i-1].x, p[i-1].y);
     y0=p[i-1].y;
    }
  }
  printf("%d",c);        
}

void move()
{
  int i=1;
  int j=1;
  while(i<=n)
  {
   while(p[j].b!=0)j++;
   p[i]=p[j];
   i++;
   j++;
  }
  
     
}

int main()
{
  scanf("%d",&n);    
  for(int i=1;i<=n;i++) {scanf("%d%d", &p[i].x, &p[i].y); p[i].k=i; }
  sort(p+1,p+n+1,cmp);
  search();
  printf(" ");        
  move();
  search();
  printf("\n");        
 
  
}
