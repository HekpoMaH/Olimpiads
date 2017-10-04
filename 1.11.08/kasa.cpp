//kasa
#include<iostream>
using namespace std;
int main()
{
    int a1,a2;
    cin>>a1>>a2;
    int e1,d1,s1,e2,d2,s2;
    e1=a1%10;
    d1=a1/10%10;
    s1=a1/100;
    e2=a2%10;
    d2=a2/10%10;
    s2=a2/100;
    int en,dn,sn;
    int e,d;
    sn=s1+e2;
    if(sn>=10&&sn<=99){
                       e=sn%10;
                       d=sn/10;
                       sn=e+d;
                       }
     dn=d1+d2;
     if(dn>=10&&dn<=99){
                        e=dn%10;
                        d=dn/10;
                        dn=e+d;
                        }
      en=e1+s2;
      if(en>=10&&en<=99){
                         e=en%10;
                         d=en/10;
                         en=e+d;
                         }
      int n;
      n=sn*100+dn*10+en;
      cout<<n<<endl;
      system("pause");
      return 0;
      }                                                       
    
