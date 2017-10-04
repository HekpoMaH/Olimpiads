#include<iostream>
#include<string>
using namespace std;
unsigned long long a,b,mxd1,mxd2,br,last;
string adv,bdv;
int main()
{
  cin>>a>>b;
  while(a>1)
  {
    adv+=a%2+'0';
    a/=2;
  }
  adv+=a+'0';
  while(b>1)
  {
    bdv+=b%2+'0';
    b/=2;
  }
  bdv+=b+'0';
  reverse(adv.begin(),adv.end());
  reverse(bdv.begin(),bdv.end());
  last=0;
  //cout<<adv<<endl<<bdv<<endl;
  for(int i=1;i<adv.size();i++)
  {
    //cout<<adv[last]<<" "<<adv[i]<<endl;
    if(adv[i]==adv[i-1]){br++;}
    else
    {
      //cout<<br<<endl;
      if(br>mxd1)mxd1=br;
      br=0;
    }
    last=i;
  }if(br>mxd1)mxd1=br;
  br=0;last=0;
  for(int i=1;i<bdv.size();i++)
  {
    if(bdv[i]==bdv[last])br++;
    else
    {
      if(br>mxd2)mxd2=br;
      br=0;
    }
    last=i;
  }
  if(br>mxd2)mxd2=br;
  //cout<<mxd1<<" "<<mxd2<<endl;
  int mx=max(mxd1,mxd2);
  string z="";
  for(int i=0;i<=mx;i++)z+='1';
  //cout<<z<<endl;
  int c=z[0]-'0';
  for(int i=1;i<z.size();i++)c=c*2+z[i]-'0';
  cout<<c<<endl;
  return 0;
}

