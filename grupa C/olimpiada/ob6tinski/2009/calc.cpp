#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<math.h>
#include<iomanip>
using namespace std;
string dv;
long long sos;
int main()
{
  cin>>dv;
  while(dv.size()%3>0)dv='0'+dv;
  while(dv>"")
  {
    sos+=(dv[0]-'0')*4+(dv[1]-'0')*2+(dv[2]-'0');
    dv.erase(0,3);
  }
  //cout<<sos<<endl;
  if(sos%7==0)cout<<"YES"<<endl;
  else cout<<7-sos%7<<endl;
  return 0;
}
