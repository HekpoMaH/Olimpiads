#include<iostream>
using namespace std;
int main()
{
int d,m,g;
cin>>d>>m>>g;
if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
{
if(d<=31){
cout<<"Yes"<<endl;
if(d==31 && m<12){d=1; m++;}
else if(d==31 && m==12){d=1; m=1; g++;}
else if(d<31)d++;}
cout<<d<<"."<<m<<"."<<g<<endl;}
else if(d>31){
cout<<"No"<<endl;
cout<<"31"<<endl;
}
else if (m==4 && m==6 && m==9 && m==11 && d<=30){
cout<<"Yes"<<endl;
if(d==30 && m<12){d=1; m++;}
else if(d<30)d++;
cout<<d<<"."<<m<<"."<<g<<endl;
}
else if (m==4 && m==6 && m==9 && m==11 && d>30){
cout<<"No"<<endl;
cout<<"30"<<endl;}
else if(m==2 && d<=29){
cout<<"Yes"<<endl;
if(d==29){d=1; m++;}
else if(d<29)d++;
cout<<d<<"."<<m<<"."<<g<<endl;
}
else if(m==2 && d>29){cout<<"No"<<endl;cout<<"29"<<endl;}
return 0;
}
