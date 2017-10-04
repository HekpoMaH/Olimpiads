#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
struct drob
{
int x,y;
double z;
};
int nod(int a,int b)
{
  if(a<b)swap(a,b);
  int r=2,q;
  while(r)
  {
    r=a%b;
    a=b;
    b=r;
  }
return a;
}
int main()
{
  int n,i,j,r;
  drob a[25];
  cin>>n;
  for(i=1;i<=n;i++)
  {
                 cin>>a[i].x>>a[i].y;
                 r=nod(a[i].x,a[i].y);
                 a[i].x=(a[i].x)/r;
                 a[i].y=(a[i].y)/r;
                 a[i].z=(double)((double)a[i].x/(double)a[i].y);
  }
  for(i=1;i<=n;i++)for(j=i+1;j<=n;j++)
  if(a[i].z>a[j].z)
  {
    drob h=a[i];
    a[i]=a[j];
    a[j]=h;
  }
  cout<<n<<endl;
  for(i=1;i<=n;i++)cout<<a[i].x<<" "<<a[i].y<<endl;
  return 0;
}
