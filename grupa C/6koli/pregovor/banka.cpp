#include<iostream>
using namespace std;
int n,a[59],a1,b1,s1,nod,a2,b[500][5],k,y;
long long s;
int namnod(int a,int b)
{
  int r;
  while(a%b!=0)
  {
    r=a%b;
    a=b;
    b=r;
  }
  return a;
}
int main()
{
  cin>>n;
  for(int i=0;i<n;i++)cin>>a[i];
  cin>>s;
  for(int i=0;i<n-1;i++)for(int j=i+1;j<n;j++)
  {
    nod=namnod(a[i],a[j]);
    if(s%nod==0)
    {
      a1=a[i]/nod;b1=a[j]/nod;s1=s/nod;
      for(int x=-100;x<200;x++)
      {
        a2=s1-a1*x;
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
  long long mn=b[0][0];a1=0;
  for(int i=0;i<k;i++)
  {
    if(b[i][0]<mn)
    {
      mn=b[i][0];
      a1=i;
    }
  }
  cout<<mn<<endl;
  if(b[a1][2]!=0)cout<<b[a1][1]<<" "<<b[a1][2]<<endl;
  if(b[a1][4]!=0)cout<<b[a1][3]<<" "<<b[a1][4]<<endl;
  return 0;
}
