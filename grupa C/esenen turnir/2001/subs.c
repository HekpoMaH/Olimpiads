#include<iostream>
#include<string>
using namespace std;
int main()
{
  string a,b,c,d,mp="e";
  cin>>a;
  cin>>b;
  int d1,d2,o=-1;
  d1=a.size();
  d2=b.size();int d3;
  if(d1>d2)
  {

    for(int i=d1;i>=0;i--)
    {
      d3=i;
      for(int j=0;j<=d1-d3;j++)
      {
        c=a.substr(j,d3);
        o=b.find(c);
        if(o>-1){cout<<c<<endl;break;}
      }
      if(o>-1){break;}
    }
  }
  else
  {


    for(int i=d2;i>=0;i--)
    {
      d3=i;
      for(int j=0;j<=d2-d3;j++)
      {
        c=b.substr(j,d3);
        o=a.find(c);
        if(o>-1){cout<<c<<endl;break;}
      }
      if(o>-1){break;}
    }
  }
  return 0;
}
