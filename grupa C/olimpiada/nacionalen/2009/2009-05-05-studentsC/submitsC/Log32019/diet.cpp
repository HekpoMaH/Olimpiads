/*
TASK:DIET
LANG:C++
*/
#include <iostream>
using namespace std;  
int main()
{
    int g1, g2, g3;
    cin >> g1 >> g2 >> g3;
    int days=0;
    days=(g1*10+g2*20+g3*30)/60;
    cout << days << ' ';
    int r, h;
    int rez=0;
    if(g1==g2 && g2==g3){ cout << 0 << endl; return 0;}
    else if(g1<=g2 && g1<=g3){ while(abs(g1-g2)>1){rez++; g1+=2; g2-=1;}
                               while(abs(g1-g3)!=0 && abs(g2-g3)!=0){rez++; g1+=1; g2+=1; g3-=1;}
                               cout << rez << endl ; return 0;
                               }
    else if(g2<=g3 && g2<=g1){
                              g1-=g2; g3=g3-g2; g2=0; 
                              r=g1*10+g3*30;
                              h=(r/60)*2;
                              if(g1>h) {g2=h; g1-=h;
                                       if(g1<(r/60)) rez+=((r/60)-g1);
                                       cout << rez << endl; return 0;}
                              else { rez+=(r/60); cout << rez << endl; return 0;}
                              }
    else if(g3<=g1 && g3<=g2){
                              if(g1<g2) while(abs(g1-g2)>1){rez++; g1+=2; g2-=1;}
                              cout << rez << endl; return 0;
                              }
    return 0;
}
                                                   
                  
              
              
