#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int sp;
double tf[100001];
double a[100001];
double b[100001];

int n, s, dt;

long long ovtc(int i, int j)
{
  int k, m, p, v, w ;
  long long c;
  if (i==j) return 0;
  if ((j-i) == 1)
    if (tf[j]<tf[i]) return 1;
    else return 0;
  k=(i+j)/2;
  m=k-i+1; p=j-k;
  for (v=i;v<=k;v++)
    a[v-i]=tf[v];
  sort(a,a+m);

  for (v=k+1;v<=j;v++)
    b[v-k-1]=tf[v];
  sort(b,b+p);

  c=0;
  v=0;w=0;
  while ((v < m) && (w < p))
    if (b[w] < a[v])
    {
      c=c+(m-v);
      w++;
    }
    else
      v++;

  c=c+ovtc(i,k)+ovtc(k+1,j);
  return c;

}

int main()
{
  int i;
  double x,y;
  scanf("%d%d%d",&n,&s,&dt);

  for (i=1;i<=n;i++)
  {
    scanf("%d", &sp);
    tf[i]=(i-1)*dt;
    x=s*1000;y=sp;
    tf[i]=tf[i]+(x/y);
  }

  cout << ovtc(1,n) << endl;
  return 0;
}
