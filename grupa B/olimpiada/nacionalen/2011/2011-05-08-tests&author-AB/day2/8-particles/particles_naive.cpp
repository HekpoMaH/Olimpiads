//Task: particles
//Author: Rusko Shikov
//naive solution - O(n2)
#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;

int const nmax=400000;
int n;
int encount=0;
struct particle
{
  long long pos;
  long long speed;
  bool exist;
};
particle x_particles[nmax+1];
particle y_particles[nmax+1];

bool lt(particle a, particle b)
{
  return (a.pos<b.pos);
}
void input()
{
  int i, pos, speed;
  scanf("%d",&n);
  for (i=1;i<=n;i++)
  {
    scanf("%d%d",&pos,&speed);
    x_particles[i].pos=pos;
    x_particles[i].speed=speed;
  }
  for (i=1;i<=n;i++)
  {
    scanf("%d%d",&pos,&speed);
    y_particles[i].pos=pos;
    y_particles[i].speed=speed;
    y_particles[i].exist=true;
  }
}

int main()
{
  int i,j;
  input();
  sort (x_particles+1,x_particles+n+1,lt);
  sort (y_particles+1,y_particles+n+1,lt);
  for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
      if ((x_particles[i].pos*x_particles[i].speed == y_particles[j].pos*y_particles[j].speed) && y_particles[j].exist)
        {
          encount++;
          y_particles[j].exist=false;
          break;
        }
  printf("%d\n",encount);
  return 0;
}
