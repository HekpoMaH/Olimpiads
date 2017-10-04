#include <cstdio>


const int maxrunners=10000;           // maximum number of runners
const int maxlaps=1000;               // maximum number of laps

int s[maxrunners+1];
int p[maxrunners+1];

const int heapsize=1<<14;

struct he                             // heap element structure
{
  int r;                              // number of runner
  int l;                              // number of lap
  int crossingtime;                   // time (in ms) from the beginning when runner #r will cross starting line after lap #l
};

he h[heapsize];
int uh=0;

int k,n;


void addtoheap(he ne)
{
  int child, parent;
  uh++;
  h[uh]=ne;
  child=uh;
  parent=child/2;
  while (parent>=1)
    if (h[parent].crossingtime > ne.crossingtime)
    {
      h[child]=h[parent];
      child=parent;
      parent=child/2;
    }
    else
      break;
  h[child]=ne;
}

void removefromheap()
{
  int parent, child;
  he ne;
  h[1]=h[uh];
  uh--;
  parent=1;
  ne=h[1];
  child=2*parent;
  while (child <= uh)
  {
    if (child<uh)
      if (h[child+1].crossingtime < h[child].crossingtime)
        child++;
    if (ne.crossingtime > h[child].crossingtime)
    {
      h[parent]=h[child];
      parent=child;
      child=2*parent;
    }
    else
      break;
  }
  h[parent]=ne;
}

void adjustheap()
{
  int parent, child;
  he ne;
  parent=1;
  ne=h[1];
  child=2*parent;
  while (child <= uh)
  {
    if (child<uh)
      if (h[child+1].crossingtime < h[child].crossingtime)
        child++;
    if (ne.crossingtime > h[child].crossingtime)
    {
      h[parent]=h[child];
      parent=child;
      child=2*parent;
    }
    else
      break;
  }
  h[parent]=ne;
}
void input()
{
  int i;
  he wne;

  scanf("%d%d",&k,&n);
  for (i=1;i<=k;i++)
  {
    scanf("%d%d",&s[i],&p[i]);
    wne.r=i;wne.l=1;wne.crossingtime=s[i];
    addtoheap(wne);
  }
}

int main()
{
  int i,j,ct;
  int cv,cvc,maxvc;
  he wne;

  input();
  cvc=0;
  maxvc=0;
  cv=0;

  while((uh>0) && (maxvc<k))
  {
    if (cv != h[1].crossingtime)
    {
      cvc=1;
      cv=h[1].crossingtime;
    }
    else
      cvc++;
    if (cvc>maxvc)
       maxvc=cvc;
    i=h[1].r;ct=h[1].crossingtime;
    if (h[1].l<n)
    {
      h[1].l++;
      if ((h[1].l%p[i]) > 0)
        h[1].crossingtime=ct+s[i]+(h[1].l%p[i])-1;
      else
        h[1].crossingtime=ct+s[i]+p[i]-1;
      adjustheap();
    }
    else
      removefromheap();
  }
  printf("%d\n",maxvc);

  return 0;
}
