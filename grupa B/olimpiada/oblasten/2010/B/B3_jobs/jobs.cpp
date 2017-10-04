#include <stdio.h>
#include <cstdlib>

int P[10000];
int N,S;

int calc()
{
  int i,M,d,t;
  M=0;
  if(S%N)return -1;
  d=S/N;
  for(i=0;i<N;i++)
  {
    t=d-P[i];
    P[i]+=t;
    P[i+1]-=t;
    t=abs(t);
    if(t>M)M=t;
  }
  return M;
}

int main()
{
  scanf("%d",&N);
  S=0;
  for(int i=0;i<N;i++)
    {
      scanf("%d",P+i);
      S+=P[i];
    }
  printf("%d\n",calc());
  return 0;
}

