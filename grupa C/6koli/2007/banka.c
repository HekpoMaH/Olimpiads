#include <iostream>
using namespace std;
int nod(int a, int b)
{
  int r;
  while (b!=0)
  {
    r=a%b;
    a=b;
    b=r;
  }
  return a;
}
int main()
{
  int a[100],n,i,j,a1,d,x,y,k=0,b1,c1,a2;
  long s,b[10000][5],min;
  cin>>n;
  for(i=0;i<n;i++)cin>>a[i];
  cin>>s;
  for (i=0;i<n-1;i++)for (j=i+1;j<n;j++)
  {
    d=nod(a[i], a[j]);
    if (s%d==0)
    {
      a1=a[i]/d;b1=a[j]/d;c1=s/d;
      for (x=-100;x<=200;x++)
      {
        a2=c1-a1*x;
        y=a2/b1;
        if(a2==y*b1)
        if((x>=0)&&(y>=0))
        {
          b[k][0]=x+y;
          b[k][1]=a[i];
          b[k][2]=x;
          b[k][3]=a[j];
          b[k][4]=y;
          k++;
        }
      }
    }
  }
  min=b[0][0];a1=0;
  for (i=0;i<k;i++)
  if (min>b[i][0]) {min=b[i][0]; a1=i;}
  cout<<min<<endl;
  if (b[a1][2]!=0)cout<<b[a1][1]<<" "<<b[a1][2]<<endl;
  if (b[a1][4]!=0)cout<<b[a1][3]<<" "<<b[a1][4]<<endl;
  return 0;
}
