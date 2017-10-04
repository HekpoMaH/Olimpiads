#include<iostream>
#include<cstdio>
using namespace std;
//short x;
int s,n,d,br,p,a[101],min1=-10,m,ans,q;
int rec(int c)
{
  int x;
  x=s;
  if(x==0) return br;
  for(int i=n; i>=2; i--)
  {
    if(x%i==0) {br++; rec(x/i); break;}
  }
  for(int i=n; i>=1; i--)
  {
    p=x;
    p-=i; //{br++; rec(x-i); break;}
    a[i]=rec(p);
   /* for(int j=1; j<=n; j++)
    {
      if(a[j]<min1 && a[j]>=0) {min1=a[j]; m=j;}
    }*/
  }
  for(int j=1; j<=n; j++)
  {
    if(a[j]<min1 && a[j]>=0) {min1=a[j]; m=j;}
  }
  br++;
  rec(a[min1]);
}
int main()
{
  scanf("%d%d",&s,&n);
  br=2;
  ans=0;
  q=n;
  if(s>n/2)
  {
    while(1)
    {
      n*=2;
      //cout<<"n"<<" "<<n<<" ";
      n-=1;
      //cout<<n<<endl;
      ans=br;
      //cout<<"ans "<<ans<<endl;
      br++;
      //cout<<"br "<<br<<endl;
      if(n>=s) break;
    }
  }
  if(s<=q*2 && s>q) ans=2;
  if(s<=q) ans=1;
  //d=rec(s);
  cout<<ans<<endl;
  return 0;
}
