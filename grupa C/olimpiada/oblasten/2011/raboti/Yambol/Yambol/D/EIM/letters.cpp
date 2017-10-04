#include <iostream>
#include <string>
using namespace std;
int main()
{
  string duma1,duma2,duma3,duma4;
  int n,r,i,d,z,m[4]={0,0,0,0};
  int a=0;
  char ch;
  cin>>n>>ch;

  z=(int)'a'-(int)'A';

  for (i=1;i<=n;i++)
  {
    cin>>duma1>>duma2>>duma3>>duma4;


    if ( (duma1[0]==ch) || (duma1[0]==(char)( (int)ch-z ) )  )
    {
      m[0]++;
    }

    d=duma2.length();
    for (r=0;r<d;r++)
    {
      if ( (duma2[r]==ch) || (duma2[r]==(char)( (int)ch-z ) )  )
      {
        m[1]++;
        r=d;
      }
    }

    d=duma3.length();
    a=0;
    for (r=0;r<d;r++)
    {
      if ( (duma3[r]==ch) || (duma3[r]==(char)( (int)ch-z ) )  )
      {
        a++;
      }
      if (a>=2)
      {
        r=d;
        m[2]++;
      }
    }

    d=duma4.length();
    if ( (duma4[d-1]==ch) || (duma4[d-1]==(char)( (int)ch-z ) ) )
    {
      m[3]++;
    }

  }

  cout<<m[0]<<" "<<m[1]<<" "<<m[2]<<" "<<m[3]<<endl;

  return 0;
}
