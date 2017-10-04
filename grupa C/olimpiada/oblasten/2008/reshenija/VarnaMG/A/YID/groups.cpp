#include<stdio.h>
using namespace std;
double dots[512],d[512]={0.},dist[512][512]={0.};
double min=0.0;
int n,p;
void gen(int group,int groups_left,int start);
int main()
{
 int i,j;
 double S=0;
 scanf("%d%d",&n,&p);
 for(i=0;i<n;i++)
  scanf("%lf",&dots[i]);
 for(i=n-1;i>=p-1;i--)
 {
  S*=((n-i)-1);
  S+=dots[i];
  S/=(n-i);
  for(j=n-1;j>=i;j--)
  dist[i][n-1]+=(S-dots[j])*(S-dots[j]);
 }
 gen(1,p-1,0);
 printf("%.4lf",min);
 return 0;
}
void gen(int group,int groups_left,int start)
{
 int j,end;
 double S,sum=0.0,D=0.0;
 if(!groups_left)
 {
  d[group]=dist[start][n-1];
  for(end=1;end<=p;end++)
   sum+=d[end];
  if(min>sum||min==0)min=sum;
  return;
 }
 for(end=start+1;end<=n-groups_left;end++)
 {
  D=0;
  S*=((end-start)-1);
  S+=dots[end-1];
  S/=(end-start);
  if(!dist[start][end-1])
  {
   for(j=start;j<end;j++)
    D+=(S-dots[j])*(S-dots[j]);
   dist[start][end-1]=D;
  }
  d[group]=dist[start][end-1];
  gen(group+1,groups_left-1,end);
 }
 return;
}
