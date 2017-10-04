#include<iostream>
#include<cmath>
#include<math.h>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
  int d,m,y;
  cin>>y>>m>>d;
  long long dni=0,dni2=0;
  dni=366*((y-1)/4-(y-1)/100+(y-1)/400)+365*(y-1-((y-1)/4-(y-1)/100+(y-1)/400));
  dni2=366*((1900-1)/4-(1900-1)/100+(1900-1)/400)+365*(1900-1-((1900-1)/4-(1900-1)/100+(1900-1)/400))+1;
  //cout<<dni<<endl;
  int mes[14];
  mes[1]=31;mes[2]=28;mes[3]=31;mes[4]=30;mes[5]=31;mes[6]=30;
  mes[7]=31;mes[8]=31;mes[9]=30;mes[10]=31;mes[11]=30;mes[12]=31;
  if((y%4==0&&y%100!=0)||(y%400==0))mes[2]=29;
  for(int i=1;i<m;i++)dni+=mes[i];
  dni+=d;
  dni-=dni2;
  if(dni>=0)
  {
      if(dni%7==0)cout<<"monday"<<endl;
      if(dni%7==1)cout<<"tuesday"<<endl;
      if(dni%7==2)cout<<"wednesday"<<endl;
      if(dni%7==3)cout<<"thursday"<<endl;
      if(dni%7==4)cout<<"friday"<<endl;
      if(dni%7==5)cout<<"saturday"<<endl;
      if(dni%7==6)cout<<"sunday"<<endl;
  }
  if(dni<0)
  {
      //cout<<dni<<" "<<(-dni)<<endl;
      if((-dni)%7==0)cout<<"monday"<<endl;
      if((-dni)%7==1)cout<<"sunday"<<endl;
      if((-dni)%7==2)cout<<"saturday"<<endl;
      if((-dni)%7==3)cout<<"friday"<<endl;
      if((-dni)%7==4)cout<<"thursday"<<endl;
      if((-dni)%7==5)cout<<"wednesday"<<endl;
      if((-dni)%7==6)cout<<"tuesday"<<endl;
  }
  return 0;
}
