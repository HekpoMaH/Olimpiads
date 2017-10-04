#include <iostream>
#include <sstream>

using namespace std;

int cifri(long long a)
{
  long long c=0;
  while(a!=0)
  {
    a/=10;
    c++;
  }
  return c;
}

int getmulti(long long a)
{
  long long c=1;
  while(a!=0)
  {
    a/=10;
    c*=10;
  }
  return c/10;
}

int main()
{
    long long n,c=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
      long long k;cin>>k;
      long long m=k*k;
      long long l=cifri(k);
      long long mc=cifri(m);
      long long a=0,b=0;
      if(mc==l*2)
      {
        long long multi=getmulti(k);
        stringstream s;
        s<<m;
        for(int j=0;j<l;j++)
        {
          char d;
          s.get(d);
          if(d-48==0)
            multi/=10;
            else
            {
          a+=(d-48)*multi;
          multi/=10;
            }
        }
        multi=getmulti(k);
        for(int j=0;j<l;j++)
        {
          char d;
          s.get(d);
          if(d-48==0)
            multi/=10;
            else
            {
          b+=(d-48)*multi;
          multi/=10;
            }
        }
      }
      else
      {
        long long multi=getmulti(k/10);
        stringstream s;
        s<<m;
        for(int j=0;j<l-1;j++)
        {
          char d;
          s.get(d);
          if(d-48==0)
            multi/=10;
            else
            {
          a+=(d-48)*multi;
          multi/=10;
            }
        }
        multi=getmulti(k);
        for(int j=0;j<l;j++)
        {
          char d;
          s.get(d);
            if(d-48==0)
            multi/=10;
            else
            {
          b+=(d-48)*multi;
          multi/=10;
            }
        }
      }
      if(a+b==k)
      c++;
    }
    cout<<c<<endl;
    return 0;
}
