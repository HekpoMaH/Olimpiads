#include<iostream>
using namespace std;
int main ()
{
    long dd,mm,gggg,p=0;
    cin>>dd>>mm>>gggg;
    if (mm==2)
    {
              if (((gggg%4==0) && ((gggg%100!=0) || (gggg%400==0)))) p=29;
              else p=28;
              }
              else
              {
                  if (mm==1 || mm==3|| mm==5 || mm==7 || mm==8 || mm==10 || mm==12) p=31;
                  else p=30;
                  }
                  if ((dd<p) || (mm>12)) dd=dd+1;
                  if (mm<12) mm=mm;
              
                  if ((dd>p) || (mm>12)) {cout<<"No"<<endl;cout<<p<<endl;}
                   else {cout<<"Yes"<<endl;cout<<dd<<"."<<mm<<"."<<gggg<<endl;}
                   return 0;
                   }
                   
                   
