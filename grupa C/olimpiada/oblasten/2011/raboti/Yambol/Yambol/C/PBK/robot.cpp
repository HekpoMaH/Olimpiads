#include<iostream>
#include<algorithm>
using namespace std;
long long m,n,r,k,s;
long long x,y,fl,fl2;
int main()
{
  long long i,j;
  cin>>m>>n>>r>>k;
  s=0;
  x=r/n;
  if(r%n==0)
    y=n;
  else
  {
    x++;
    y=r%n;
  }
  if(x%2==y%2)
    fl=0;
  else
    fl=1;
  for(i=1;i<=m;i++)
    for(j=1;j<=n;j++)
    {
      if(i%2==j%2)
        fl2=0;
      else
        fl2=1;
      if(abs(x-i)+abs(y-j)<=k)
        if((k%2==1 && fl!=fl2) || (k%2==0 && fl==fl2))
          s=s+((i-1)*n+j);
    }
  cout<<s<<endl;
}
