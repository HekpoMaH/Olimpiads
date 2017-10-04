//Task: particles
//Author: Rusko Shikov
//solution O(nlogn)
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
  long long pos;
};

bool lt(particle a, particle b)
{
  return ((a.pos_speed<b.pos_speed) || ((a.pos_speed==b.pos_speed) && (a.pos<b.pos)));
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
    y_particles[i].pos=pos;
    y_particles[i].pos_speed=pos*speed;
  }
}

int main()
{
  int ukx,uky;
  input();
  sort(x_particles+1,x_particles+n+1,lt);
  sort(y_particles+1,y_particles+n+1,lt);
  ukx=1;uky=1;
  while ((ukx<=n) && (uky<=n))
    if (x_particles[ukx].pos_speed == y_particles[uky].pos_speed)
    {
      encount++;
      ukx++;
      uky++;
    }
    else
      if (x_particles[ukx].pos_speed<y_particles[uky].pos_speed)
        ukx++;
      else
        uky++;
  printf("%d\n",encount);
  return 0;
}
