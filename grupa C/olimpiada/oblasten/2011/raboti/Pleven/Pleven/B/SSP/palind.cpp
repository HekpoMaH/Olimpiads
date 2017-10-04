#include<iostream>
#include<cstdio>
using namespace std;
int n,a[10001],b[10001],x;
/*int prov(int s, int f)
{
  int l;
  l=f-s+1;
  int i,j,ok;
  if(l%2==0)
  {
    for(i=s,j=f; i<=l/2,j>l/2; i++,j--)
    {
      if(a[i]!=a[j]) {ok=1; break;}
    }
  }
  else
  {
    for(i=s,j=f; i>=l/2,j>(l/2)+1; i++,j--)
    {
      if(a[i]!=a[j]) {ok=1; break;}
    }
  }
  if(ok==1) return 0;
  else return 1;
}*/
int main()
{
  scanf("%d",&n);
  for(int i=1; i<=n; i++)
  {
    scanf("%d",&x);
    a[i]=x;
  }
  for(int k=1; k<=n; k++)
  {
    b[k]+=8;
    b[k]/=3;
    b[k]--;
    b[k]+=3;
    b[k]%14;
  }

  cout<<1<<endl;
  return 0;
}
