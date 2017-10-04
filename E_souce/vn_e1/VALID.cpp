#include<iostream>
using namespace std;
int main () {
 int d,m,g;
 cin>>d>>m>>g;
 if ((m==1||m==3||m==5||m==7||m==8||m==10||m==12)&&d>31) cout<<"No\n"<<"31"<<endl; 
 if (m==2&&d>29) cout<<"No\n"<<"29"<<endl;
 if ((m==4||m==6||m==9||m==11)&&d>30) cout<<"No\n"<<"30"<<endl;
     if ((m==1||m==3||m==5||m==7||m==8||m==10||m==12)&&d<=31) {
     {
     cout<<"Yes\n";
     d++;
     if (d==32) {m++;d=1;
     if (m==13) {m=1;d=1;g=2009;}
     }
      
    
  
     if ((m==4||m==6||m==9||m==11)&&d<=30) {
                                         cout<<"Yes\n";
                                         d++;
                                         if (d==31) {m++;d=1;}
                                         }   
     if ((m==2)&&(d<=29)) {
                      cout<<"Yes\n";
                      d++;
                      if (d==30) {m=3;d=1;}
                      }
     cout<<d<<"."<<m<<"."<<g<<endl;
     }
     }
    //system ("pause");
    return 0;
}
