#include<iostream>
using namespace std;
long long m10,m20,m30,ost10,ost20,ost30,dni,br;
int main()
{
  cin>>m10>>m20>>m30;
  dni=(long long)(m10*10+m20*20+m30*30)/60;
  cout<<dni<<" ";
  ost10=m10-dni;
  ost20=m20-dni;
  ost30=m30-dni;
  //cout<<ost10<<" "<<ost20<<" "<<ost30<<endl;
  if(ost20<0)
  {
    while(ost20<0&&ost10>1)
    {
      ost20++;
      ost10-=2;
    }
    while(ost20<0&&ost30>0)
    {
      ost30--;
      ost20++;
      ost10++;
      if(ost10>1){ost10-=2;ost20++;}
      br++;
    }
  }
  if(ost30<0)
  {
    while(ost10>0&&ost20>0&&ost30<0)
    {
      ost10--;
      ost20--;
      ost30++;
    }
    while(ost10>2&&ost30<0)
    {
      ost10-=3;
      ost30++;
    }
    while(ost20>0&&ost30<0)
    {
      ost20--;
      br++;
      ost10+=2;
      while(ost20>0&&ost10>0&&ost30<0)
      {
        ost30++;
        ost20--;
        ost10--;
      }
    }
    while(ost10>2&&ost30<0)
    {
      ost10-=3;
      ost30++;
    }
  }
  if(ost10<0)
  {
    if(ost20==0&&ost30>0){ost30--;ost20++;ost10++;br++;}
    while(ost20>0&&ost10<0)
    {
      ost20--;
      ost10+=2;
      //if(ost20==0)cout<<"a"<<endl;
      if(ost20==0&&ost30>0&&ost10<0)
      {//cout<<"at"<<endl;
        ost30--;
        br++;
        ost20++;
        ost10++;
      }
      br++;
    }
    //cout<<ost10<<" "<<ost20<<" "<<ost30<<endl;
  }
  cout<<br<<endl;
  return 0;
}
