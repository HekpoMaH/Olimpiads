//Task: particles
//Author: Rusko Shikov
//solution O(nlogn) with bigger constant
#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;

int const nmax=400000;
int n;
int encount=0;
struct particle
{
  long long pos_speed;
  bool exist;
  long long pos;
};

bool lty(particle a, particle b)
{
  return ((a.pos_speed<b.pos_speed) || ((a.pos_speed==b.pos_speed) && (a.pos<b.pos)));
}

bool ltx(particle a, particle b)
{
  return (a.pos<b.pos);
}

particle x_particles[nmax+1];
particle y_particles[nmax+1];

void input()
{
  int i, pos, speed;
  scanf("%d",&n);
  for (i=1;i<=n;i++)
  {
    scanf("%d%d",&pos,&speed);
    x_particles[i].pos=pos;
    x_particles[i].pos_speed = pos*speed;
  }
  for (i=1;i<=n;i++)
  {
    scanf("%d%d",&pos,&speed);
    y_particles[i].pos_speed=pos*speed;
    y_particles[i].exist=true;
    y_particles[i].pos=pos;
  }
}

int bsearch(long long a)
{
  int l,r,k;
  l=1; r=n;
  while (l<=r)
  {
    k=(l+r)/2;
    if ((a<y_particles[k].pos_speed) || ((a==y_particles[k].pos_speed) && y_particles[k].exist))
      r=k-1;
    else
      l=k+1;
  }
  if ((a==y_particles[l].pos_speed) && (y_particles[l].exist))
    return l;
  else
    return 0;
}

int main()
{
  int i,j;
  input();
  sort(x_particles+1,x_particles+n+1,ltx);
  sort(y_particles+1,y_particles+n+1,lty);
  for (i=1;i<=n;i++)
  {
    j=bsearch(x_particles[i].pos_speed);
    if (j>0)
    {
      encount++;
      y_particles[j].exist=false;
    }
  }
  printf("%d\n",encount);
  return 0;
}
