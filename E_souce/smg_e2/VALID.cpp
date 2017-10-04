#include<iostream.h>
using namespace std;
int main(){
int d,m,g;
cin>>d>>m>>g;
if(g==2008){
if(m==12){
if(d<=31&&d>=1){cout<<"YES\n";}
if(d==31){cout<<"1.1."<<g+1;}
else{cout<<d+1<<m<<g;}
}
if(m==1||m==3||m==5||m==7||m==8||m==10){
if(d<=31&&d>=1){cout<<"YES\n";
if(d==31){cout<<"1."<<m+1<<"."<<g;}
else{cout<<d+1<<"."<<m<<"."<<g;}
}
else{cout<<"NO\n"<<"31";}
}
if(m==4||m==6||m==9||m==11){
if(d<=30&&d>=1){cout<<"YES\n";
if(d==30){cout<<"1."<<m+1<<"."<<g;}
else{cout<<d+1<<"."<<m<<"."<<g;}
}
else{cout<<"NO\n"<<"30";}
}
if(m==2){
if(d<=29&&d>=1){cout<<"YES\n";
if(d==29){cout<<"1."<<m+1<<g;}
else{cout<<d+1<<"."<<m<<"."<<g;}
}
else{cout<<"NO\n"<<"29";}
}
}
return 0;
}
