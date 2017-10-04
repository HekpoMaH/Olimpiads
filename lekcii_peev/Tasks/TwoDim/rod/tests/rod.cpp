#include<cstdio>
#include<climits>
using namespace std;

const int N_max=1001;
int N;
int c[N_max];
int s[N_max][N_max];
int t[N_max][N_max];

void dp()
{
 for(int k=0;k<=N-2;k++)
 {
  int i=k;
  int j=k+2;
  t[i][j]=s[i][j];
 }

 for(int r=3;r<=N;r++)
 for(int k=0;k<=N-r;k++)
 {
  int i=k;
  int j=k+r;
  int m=INT_MAX;
  for(int p=i+1;p<=j-1;p++)
  {
   int v1=t[i][p];
   int v2=t[ p][j];
   int v=v1+v2;
   if(m>v)m=v;
  }
  t[i][j]=m+s[i][j];
 }
}

int main()
{
 scanf("%i", &N);
 for(int j=1;j<=N;j++) scanf("%i",&c[j]);

 for(int j=1;j<=N;j++)
 for(int i=0;i<j;i++)
 { int v=0;
   for(int k=i+1;k<=j;k++) v += c[k];
   s[i][j]=v;
 }
 dp();
 printf("%i\n",t[0][N]);
}
