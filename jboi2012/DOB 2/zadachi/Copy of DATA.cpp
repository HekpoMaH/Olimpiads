//DATA
#include<iostream>
using namespace std;
int main()
{
    int s,d,m,g,od,br;
    cin>>d>>m>>g;
    if(m==2)
    {
            if(g%4==0&&g%100!=0||g%400==0){
                                           br=29;
                                           }
            else{
                 br=28;
                }
    }       
    else {
         if(m==4||m==6||m==9||m==11){br=30;}
          else{br=31;}
          }    
    if(d<br-7){d=d+7;}
    else{
         od=br-d;
         
         cout<<od<<" "<<br<<" "<<d<<"\n";
         if(m<12){m++;s=7-od; d=s;}
         else{m=1;s=7-od;d=s;g++;}
         }
    cout<<d<<"-"<<m<<"-"<<g<<endl;
    system("pause");
    return 0;
}
    
         
