#include <cstdio>
#include <queue>

using namespace std;

const int maxrunners=10000;           // maximum number of runners
const int maxlaps=1000;               // maximum number of laps

int s[maxrunners+1];
int p[maxrunners+1];

struct elpq
{
  int r;                              // number of runner
  int l;                              // number of lap
  int crossingtime;                   // time (in ms) from the beginning when runner #r will cross starting line after lap #l
  bool operator <(const elpq &a) const
  {
    if (crossingtime>a.crossingtime)
      return true;
    else
      return false;
  }
};

int k,n;

priority_queue<elpq> pq;

void input()
{
  int i;
  elpq el;

  scanf("%d%d",&k,&n);
  for (i=1;i<=k;i++)
  {
    scanf("%d%d",&s[i],&p[i]);
    el.r=i;el.l=1;el.crossingtime=s[i];
    pq.push(el);
  }
}

int main()
{
  int cv,cvc,maxvc;
  elpq el;
  input();
  cvc=0;
  maxvc=0;
  cv=0;

  while((!pq.empty()) && (maxvc<k))
  {
    el=pq.top();
    if (cv != el.crossingtime)
      {
        cvc=1;
        cv=el.crossingtime;
      }
    else
      cvc++;
    if (cvc>maxvc)
      maxvc=cvc;
    pq.pop();
    if (el.l<n)
    {
      el.l++;
      if ((el.l%p[el.r]) > 0)
        el.crossingtime=el.crossingtime+s[el.r]+(el.l%p[el.r])-1;
      else
        el.crossingtime=el.crossingtime+s[el.r]+p[el.r]-1;
      pq.push(el);
    }
  }

  printf("%d\n",maxvc);

  return 0;
}







