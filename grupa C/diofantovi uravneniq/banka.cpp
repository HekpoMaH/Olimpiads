#include<iostream>
#include<algorithm>
using namespace std;
int n,a[55];
long long s;
int k,c1;
int y,noda,a1,b1,a2,b[10000][5];//ax+by=c
//a1=x,b1=y,a2=ost. pari
int nod(int a,int b)
{
  int r;
  while(b!=0)
  {
    r=a%b;
    a=b;b=r;
  }
  return a;
}

int main()
{
  cin>>n;
  for(int i=0;i<n;i++)cin>>a[i];
  cin>>s;
  for(int i=0;i<n-1;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      noda=nod(a[i],a[j]);
      if(s%noda==0)
      {
        a1=a[i]/noda;
        b1=a[j]/noda;
        c1=s/noda;
        for(int x=-100;x<=200;x++)
        {
          a2=c1-a1*x;
          y=a2/b1;
          if(a2==y*b1&&x>=0&&y>=0)
          {
            b[k][0]=x+y;//ob6t broi banknoti
            b[k][1]=a[i];//vid banknota 1
            b[k][2]=x;
            b[k][3]=a[j];//vid banknota 2
            b[k][4]=y;
            k++;
          }
        }
      }
    }
  }
  int mn=b[0][0];a1=0;
  for(int i=0;i<k;i++)
  {
    if(b[i][0]<mn){mn=b[i][0];a1=i;}
  }
  cout<<mn<<endl;
  if(b[a1][2]!=0)cout<<b[a1][1]<<" "<<b[a1][2]<<endl;
  if(b[a1][4]!=0)cout<<b[a1][3]<<" "<<b[a1][4]<<endl;
  return 0;
}
