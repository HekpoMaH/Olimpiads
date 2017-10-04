#include<iostream>
#include<string>
#include<cstring>
#include<math.h>
#include<cmath>
#include<algorithm>
#include<iomanip>
using namespace std;
string dv,sh,s,a="ABCDEF";
void prom()
{
  int des,ost;
  for(int i=dv.size()-1;i>=0;i-=4)
  {
    s=dv[i]+dv[i-1]+dv[i-2]+dv[i-3];
    for(int j=s.size()-1;j>=0;j--)
    {
      des=(s[j]-'0')*pow((double)2,j);
    }
    while(des>=16)
    {
      ost=des%16;
      if(ost>9)
      {
        sh+=a[ost-9];
      }
      else sh+=ost;
      des/=16;
    }
    if(des>0)sh+=des;
    des=0;

  }reverse(sh.begin(),sh.end());
}
int main()
{
  cin>>dv;
  cout<<sh<<endl;
  return 0;
}
