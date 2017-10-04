#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int n,a[64];
long long ans,val[64];
char inp[64];

long long solve(int pos)
{
  long long k=0,x=0,y=0;

  if (pos == n) return inp[pos-1]-'0';

  if (inp[pos] == '+') a[pos]=0;
  else
  if (inp[pos] == '-') a[pos]=1;
  else
  {
    if (pos == 1) a[pos]=0;
    else a[pos]=a[pos-2];
  }

  val[pos]=solve(pos+2);
  k=val[pos];

  if (pos == n-2)
  {
    if (inp[pos] == '-') return (inp[pos-1]-'0')-k;
    else
    if (inp[pos] == '+') return (inp[pos-1]-'0')+k;
    else return (inp[pos-1]-'0')*k;
  }

  if (inp[pos] == '-')
  {
    x=(inp[pos-1]-'0')-k;
    y=(inp[pos-1]-'0')-(inp[pos+1]-'0');
  }
  else
  if (inp[pos] == '+')
  {
    x=(inp[pos-1]-'0')+k;
    y=(inp[pos-1]-'0')+(inp[pos+1]-'0');
  }
  else
  {
    x=(inp[pos-1]-'0')*k;
    y=(inp[pos-1]-'0')*(inp[pos+1]-'0');
  }
  if (inp[pos+2] == '*') y*=val[pos+2];
  else
  if (inp[pos+2] == '+') y+=val[pos+2];
  else
  if (inp[pos+2] == '-') y-=val[pos+2];

  if (pos == 1)
  {
    if (x < y) return x;
    else return y;
  }
  else
  if (a[pos-2]==0)
  {
    if (x < y) return x;
    else return y;
  }
  else
  {
    if (x > y) return x;
    else return y;
  }
}

int main()
{
  cin>>inp;
  n=strlen(inp);

  ans=solve(1);
  printf("%lld\n", ans);
return 0;
}
