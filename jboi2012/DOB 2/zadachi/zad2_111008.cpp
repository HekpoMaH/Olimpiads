//zad2_111008
#include<iostream>
using namespace std;
int main()
{
    int d,m,g,br;
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
    if(d<=br-1){d++;}
    else{
         d=1;
         if(m<12){m++;}
         else{m=1;g++;}
         }
     cout<<d<<"."<<m<<"."<<g<<endl;
     system("pause");
     return 0;
     }                                             
