#include<stdio.h>
#include<algorithm>
using namespace std;

double shema[512][512];
double si[512][512];
double mas[512];

int n,p;

double rec(int i,int pos)
{
    int j;
    double c=1e100;
    if(si[i][pos]>=0)return si[i][pos];
    if(i==1)return shema[0][pos];
    for(j=pos;j>=i-1;j--)
    {
     c=min(c,rec(i-1,j-1)+shema[j][pos]);
    }
    si[i][pos]=c;
return c;
}

int main()
{
    int i,j;
    double ans=0;
    double c=0,c2=0;
    
    scanf("%d%d",&n,&p);
    for(i=0;i<n;i++)scanf("%lf",&mas[i]);
    
    for(i=0;i<n;i++)
    {
     c=0.0;
     for(j=i;j<n;j++)
     {
      c+=mas[j];
      si[i][j]=c/(j-i+1);
     }
    }
    
    for(i=0;i<n;i++)
    {
     c=0.0;
     c2=0.0;
     for(j=i;j<n;j++)
     {
      c+=mas[j]*mas[j];
      c2+=mas[j];
      shema[i][j]=(j-i+1)*si[i][j]*si[i][j]+c+c2*si[i][j]*-2;
      si[i][j]=-1.0;
     }
    }
    
    ans=rec(p,n-1);
    printf("%.4lf\n",ans);
return 0;
}

