#include<cstdio>
using namespace std;
struct point
{
 int x,y;
};
int n,u[15],m=2000000;
point a[15];
void rek(int i,int num,int s)
{
 if(num==n)
 {
  if(s<m)m=s;
  return;
 }
 int i2,k1,k2,m1,m2;
 k1=a[i].x-a[i].y;
 //if(k1<0)k1=-k1;
 k2=a[i].x+a[i].y;
 for(i2=1;i2<=n*2;i2++)
  if(u[i2]==0)
  {
   u[i2]=1;
   m1=a[i2].x-a[i2].y;
   //if(m1<0)m1=-m1;
   m2=a[i2].x+a[i2].y;
   //printf("%d %d   ---   %d %d %d %d   ---- ",i,i2,k1,k2,m1,m2);
   m1-=k1;
   m2-=k2;
   if(m1<0)m1=-m1;
   if(m2<0)m2=-m2;
   //printf("%d %d\n",m1,m2);
   rek(i2,num+1,s+((m1+m2)/2));
   u[i2]=0;
  }
}
int main()
{
 int i;
 scanf("%d",&n);
 for(i=1;i<=n*2;i++)scanf("%d%d",&a[i].x,&a[i].y);
 a[0].x=0;
 a[0].y=0;
 rek(0,0,0);
 printf("%d\n",m);
 return 0;
}
