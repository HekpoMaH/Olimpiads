#include <iostream>
#include <string>
using namespace std;
const int MAXM=50;
char s[MAXM];
int a[MAXM], b[MAXM];
int m,k,key=0;
void print(unsigned i)
{
  unsigned l,r=0;
  if(key==0)
  {
    r=0;
    while((a[b[r]-1]==0)&&(r<=i-1))r++;
    if(r==i)cout<<"0 ";
    else
    {
      for (l=r;l<=i-1;l++)cout<<a[b[l]-1];
      cout<<" ";
    }
  }
}
int sum(unsigned i)
{
  int s=0;
  unsigned l;
  for(l=0;l<=i-1;l++)s+=a[b[l]-1];
  return s;
}
void comb(unsigned i, unsigned after)
{
  unsigned j;
  int ss;
  if(i>k)return;
  if(key==0)for(j=after+1;j<=m;j++)
  {
     b[i-1]=j;
     if((i==k)&&(key==0))
     {
      ss=sum(i);
      if(ss%3==0){print(i);key=1;}
     }
     comb(i+1,j);
  }
}
void sortg(int m)
{
  unsigned i,j;
  int t;
  for (i=0;i<m-1;i++)for(j=0;j<m-i-1;j++)
  if(a[j]<a[j+1])
  {
    t=a[j]; a[j]=a[j+1]; a[j+1]=t;
  }
}
void sortl(int m)
{
  unsigned i,j;
  int t;
  for (i=0;i<m-1;i++)for(j=0;j<m-i-1;j++)
  if(a[j]>a[j+1])
  {
    t=a[j]; a[j]=a[j+1]; a[j+1]=t;
  }
}
int main()
{
  int i;
  cin >>s;
  cin >>k;
  m=strlen(s);
  for(i=0;i<m;i++)a[i]=s[i]-'0';
  sortl(m);
  comb(1,0);
  sortg(m);
  key=0;
  comb(1,0);
  if(key==0)cout<<"-1";
}
