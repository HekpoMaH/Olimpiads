#include<iostream>
using namespace std;
long long n,a,b,c,b1,c1,s,s1,br_c,br;
long long max(long long a,long long b,long long c)
{
  if(a>b&&a>c)return a;
  else if(b>c)return b;
  else return c;
}
int main()
{
  cin>>a>>b>>c>>br>>s;
  b1=b-a;
  c1=c-a;
  s1=s-br*a;
  n=br+1;
  br_c=s1/c1;
  long long j,k;
  for(int i=br_c;i>=0;i--)
  {
    j=(s1-i*c1)/b1;
    if(i*c1+j*b1==s1)
    {
      k=br-i-j;
      if(abs(i-j)<n&&abs(j-k)<n&&abs(i-k)<n)n=max(abs(i-j),abs(i-k),abs(j-k));
    }
  }
  cout<<n<<endl;
  return 0;
}
